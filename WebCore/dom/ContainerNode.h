/*
 * Copyright (C) 1999 Lars Knoll (knoll@kde.org)
 *           (C) 1999 Antti Koivisto (koivisto@kde.org)
 *           (C) 2001 Dirk Mueller (mueller@kde.org)
 * Copyright (C) 2004, 2005, 2006, 2007, 2009 Apple Inc. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 */

#ifndef ContainerNode_h
#define ContainerNode_h

#include "Node.h"
#include "FloatPoint.h"

namespace WebCore {
    
typedef void (*NodeCallback)(Node*);

namespace Private { 
    template<class GenericNode, class GenericNodeContainer>
    void addChildNodesToDeletionQueue(GenericNode*& head, GenericNode*& tail, GenericNodeContainer* container);
};

class ContainerNode : public Node {
public:
    virtual ~ContainerNode();

    Node* firstChild() const { return m_firstChild; } /* 孩子中的第一个 */
    Node* lastChild() const { return m_lastChild; } /* 孩子中的最后一个 */

    virtual bool insertBefore(PassRefPtr<Node> newChild, Node* refChild, ExceptionCode&, bool shouldLazyAttach = false); /* 插入一个子节点 */
    virtual bool replaceChild(PassRefPtr<Node> newChild, Node* oldChild, ExceptionCode&, bool shouldLazyAttach = false); /* 替换一个子节点*/
    virtual bool removeChild(Node* child, ExceptionCode&); /* 删除一个子节点 */
    virtual bool appendChild(PassRefPtr<Node> newChild, ExceptionCode&, bool shouldLazyAttach = false); /* 加入一个子节点 */

    virtual ContainerNode* addChild(PassRefPtr<Node>);
    bool hasChildNodes() const { return m_firstChild; }
    virtual void attach();	/* 设置该节点和所有孩子节点加入到渲染树的状态为真 */
    virtual void detach();      /* 把该节点从渲染树中移出 */
    virtual void willRemove();
    virtual IntRect getRect() const; /* 得到该节点在页面的包围矩形 */
    virtual void setFocus(bool = true); /* 设置该节点是否有焦点 */
    virtual void setActive(bool active = true, bool pause = false);
    virtual void setHovered(bool = true);
    unsigned childNodeCount() const; /* 得到子节点个数 */
    Node* childNode(unsigned index) const; /* 得到第i个子节点 */

    virtual void insertedIntoDocument();
    virtual void removedFromDocument();
    virtual void insertedIntoTree(bool deep);
    virtual void removedFromTree(bool deep);
    virtual void childrenChanged(bool createdByParser = false, Node* beforeChange = 0, Node* afterChange = 0, int childCountDelta = 0); /* 节点发生改变调用 */

    virtual bool removeChildren();

    void removeAllChildren();

    void cloneChildNodes(ContainerNode* clone);
    
    bool dispatchBeforeLoadEvent(const String& sourceURL);

protected:
    ContainerNode(Document*, ConstructionType = CreateContainer);

    static void queuePostAttachCallback(NodeCallback, Node*);
    void suspendPostAttachCallbacks();
    void resumePostAttachCallbacks();

    template<class GenericNode, class GenericNodeContainer>
    friend void appendChildToContainer(GenericNode* child, GenericNodeContainer* container);

    template<class GenericNode, class GenericNodeContainer>
    friend void Private::addChildNodesToDeletionQueue(GenericNode*& head, GenericNode*& tail, GenericNodeContainer* container);

    void setFirstChild(Node* child) { m_firstChild = child; } /* 设置第一个子节点 */
    void setLastChild(Node* child) { m_lastChild = child; }   /* 设置最后一个子节点 */
    
private:
    static void dispatchPostAttachCallbacks();
    
    bool getUpperLeftCorner(FloatPoint&) const; /* 得到该节点在页面左上角的顶点 */
    bool getLowerRightCorner(FloatPoint&) const; /* 得到该节点在页面右下角的顶点 */

    Node* m_firstChild;		/* (在兄弟姐妹中)指向上个节点 */
    Node* m_lastChild;		/* (在兄弟姐妹中)指向下个节点 */
};

inline ContainerNode::ContainerNode(Document* document, ConstructionType type)
    : Node(document, type)
    , m_firstChild(0)
    , m_lastChild(0)
{
}

inline unsigned Node::containerChildNodeCount() const
{
    ASSERT(isContainerNode());
    return static_cast<const ContainerNode*>(this)->childNodeCount();
}

inline Node* Node::containerChildNode(unsigned index) const
{
    ASSERT(isContainerNode());
    return static_cast<const ContainerNode*>(this)->childNode(index);
}

inline Node* Node::containerFirstChild() const
{
    ASSERT(isContainerNode());
    return static_cast<const ContainerNode*>(this)->firstChild();
}

inline Node* Node::containerLastChild() const
{
    ASSERT(isContainerNode());
    return static_cast<const ContainerNode*>(this)->lastChild();
}

} // namespace WebCore

#endif // ContainerNode_h
