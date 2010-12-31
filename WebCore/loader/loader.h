/*
    Copyright (C) 1998 Lars Knoll (knoll@mpi-hd.mpg.de)
    Copyright (C) 2001 Dirk Mueller <mueller@kde.org>
    Copyright (C) 2004, 2006, 2007, 2008 Apple Inc. All rights reserved.

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#ifndef loader_h
#define loader_h

#include "AtomicString.h"
#include "AtomicStringImpl.h"
#include "FrameLoaderTypes.h"
#include "PlatformString.h"
#include "SubresourceLoaderClient.h"
#include "Timer.h"
#include <wtf/Deque.h>
#include <wtf/HashMap.h>
#include <wtf/Noncopyable.h>

namespace WebCore {

    class CachedResource;
    class DocLoader;
    class KURL;
    class Request;

    class Loader : public Noncopyable {
    public:
        Loader();
        ~Loader();

        void load(DocLoader*, CachedResource*, bool incremental = true, SecurityCheckPolicy = DoSecurityCheck, bool sendResourceLoadCallbacks = true);

        void cancelRequests(DocLoader*); 
        
        enum Priority { Low, Medium, High }; /* 资源请求的优先级别 */
        void servePendingRequests(Priority minimumPriority = Low);/* 处理阻塞的资源请求(高优先级别的资源先请求) */

        bool isSuspendingPendingRequests() { return m_isSuspendingPendingRequests; }
        void suspendPendingRequests(); /* 暂定对阻塞的资源请求的处理 */
        void resumePendingRequests();  /* 恢复对阻塞的资源请求的处理 */
        
        void nonCacheRequestInFlight(const KURL&);
        void nonCacheRequestComplete(const KURL&);

    private:
        Priority determinePriority(const CachedResource*) const; /* 确定资源的优先级别 */
        void scheduleServePendingRequests();
        
        void requestTimerFired(Timer<Loader>*);
	/* Host 对应一个域名的服务器主机 */
        class Host : public RefCounted<Host>, private SubresourceLoaderClient {
        public:
            static PassRefPtr<Host> create(const AtomicString& name, unsigned maxRequestsInFlight) 
            {
                return adoptRef(new Host(name, maxRequestsInFlight));
            }
            ~Host();
            
            const AtomicString& name() const { return m_name; }
            void addRequest(Request*, Priority); /* 添加一个请求 */
            void nonCacheRequestInFlight();
            void nonCacheRequestComplete();
            void servePendingRequests(Priority minimumPriority = Low); /* 处理阻塞的资源请求(高优先级别的资源先请求) */
            void cancelRequests(DocLoader*); /* 取消DocLoader所发送的资源请求 */
            bool hasRequests() const; /* 是否有资源请求 */

            bool processingResource() const { return m_numResourcesProcessing != 0 || m_nonCachedRequestsInFlight !=0; }

        private:
            Host(const AtomicString&, unsigned);

            virtual void didReceiveResponse(SubresourceLoader*, const ResourceResponse&);
            virtual void didReceiveData(SubresourceLoader*, const char*, int);
            virtual void didFinishLoading(SubresourceLoader*);
            virtual void didFail(SubresourceLoader*, const ResourceError&);
            
            typedef Deque<Request*> RequestQueue;
            void servePendingRequests(RequestQueue& requestsPending, bool& serveLowerPriority); /* 处理requestsPending的资源请求 */
            void didFail(SubresourceLoader*, bool cancelled = false);
            void cancelPendingRequests(RequestQueue& requestsPending, DocLoader*); /* 移出在requestsPending列表中DocLoader所属的资源请求 */
            
            RequestQueue m_requestsPending[High + 1]; /* 待请求的资源队列列表 */
            typedef HashMap<RefPtr<SubresourceLoader>, Request*> RequestMap;
            RequestMap m_requestsLoading; /* 正在处理的请求表 */
            const AtomicString m_name;	  /* 主机网络名 */
            const int m_maxRequestsInFlight;
            int m_numResourcesProcessing;
            int m_nonCachedRequestsInFlight;
        };
        typedef HashMap<AtomicStringImpl*, RefPtr<Host> > HostMap;
        HostMap m_hosts;	/* loader 处理的服务器组 */
        RefPtr<Host> m_nonHTTPProtocolHost; /* 非http协议域名服务器 */
        
        Timer<Loader> m_requestTimer;

        bool m_isSuspendingPendingRequests;
    };

}

#endif
