/*
 * Copyright (C) 2003, 2004, 2005, 2006, 2007, 2008, 2009 Apple Inc. All rights reserved.
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

#ifndef RenderOverflow_h
#define RenderOverflow_h

#include "IntRect.h"
#include "stdio.h"

#define PRINT_OVERFLOW 

namespace WebCore
{
// RenderOverflow is a class for tracking content that spills out of a box.  This class is used by RenderBox and
// InlineFlowBox.
//
// There are two types of overflow: layout overflow (which is expected to be reachable via scrolling mechanisms) and
// visual overflow (which is not expected to be reachable via scrolling mechanisms).
//
// Layout overflow examples include other boxes that spill out of our box,  For example, in the inline case a tall image
// could spill out of a line box. 
    
// Examples of visual overflow are shadows, text stroke (and eventually outline and border-image).

// This object is allocated only when some of these fields have non-default values in the owning box.
//  对应 overflow 为默认值的情况(visible).其他好像也一样的
//    开始的时候一个renderbox(A)的over flow中的LayoutOverflow和VisualOverflow都是一样的，都等于
//    这个box的大小。当解析这个box的里面的renderobject的时候，会调用addLayoutOverflow和addVisualOverflow
//    把这renderobject的大小超出的部分融合到enderbox的over flow 的LayoutOverflow和VisualOverflow中去.
//    完成后renderbox(A)的over flow就是可以现实整个对象的大小.
//    这个过程会递归的向box A的containing box传递.直到到达body对应的box为止

class RenderOverflow : public Noncopyable {
public:
    RenderOverflow(const IntRect& defaultRect = IntRect()) 
        : m_topLayoutOverflow(defaultRect.y())
        , m_bottomLayoutOverflow(defaultRect.bottom())
        , m_leftLayoutOverflow(defaultRect.x())
        , m_rightLayoutOverflow(defaultRect.right())
        , m_topVisualOverflow(defaultRect.y())
        , m_bottomVisualOverflow(defaultRect.bottom())
        , m_leftVisualOverflow(defaultRect.x())
        , m_rightVisualOverflow(defaultRect.right())
    {
#ifdef PRINT_OVERFLOW
	 printf("new overflow:");
	 printf("top:%d bottom:%d left:%d right:%d\n",defaultRect.y(),defaultRect.bottom()
		,defaultRect.x(),defaultRect.right());
#endif
    }
   
    int topLayoutOverflow() const { return m_topLayoutOverflow; }
    int bottomLayoutOverflow() const { return m_bottomLayoutOverflow; }
    int leftLayoutOverflow() const { return m_leftLayoutOverflow; }
    int rightLayoutOverflow() const { return m_rightLayoutOverflow; }
    IntRect layoutOverflowRect() const;

    int topVisualOverflow() const { return m_topVisualOverflow; }
    int bottomVisualOverflow() const { return m_bottomVisualOverflow; }
    int leftVisualOverflow() const { return m_leftVisualOverflow; }
    int rightVisualOverflow() const { return m_rightVisualOverflow; }
    IntRect visualOverflowRect() const;

    IntRect visibleOverflowRect() const;

    void setTopLayoutOverflow(int overflow) { m_topLayoutOverflow = overflow; }
    void setBottomLayoutOverflow(int overflow) { m_bottomLayoutOverflow = overflow; }
    void setLeftLayoutOverflow(int overflow) { m_leftLayoutOverflow = overflow; }
    void setRightLayoutOverflow(int overflow) { m_rightLayoutOverflow = overflow; }
    
    void setTopVisualOverflow(int overflow) { m_topVisualOverflow = overflow; }
    void setBottomVisualOverflow(int overflow) { m_bottomVisualOverflow = overflow; }
    void setLeftVisualOverflow(int overflow) { m_leftVisualOverflow = overflow; }
    void setRightVisualOverflow(int overflow) { m_rightVisualOverflow = overflow; }
    
    void move(int dx, int dy);
    
    void addLayoutOverflow(const IntRect&);
    void addVisualOverflow(const IntRect&);

    void resetLayoutOverflow(const IntRect& defaultRect);

private:
    int m_topLayoutOverflow;
    int m_bottomLayoutOverflow;
    int m_leftLayoutOverflow;
    int m_rightLayoutOverflow;

    int m_topVisualOverflow;
    int m_bottomVisualOverflow;
    int m_leftVisualOverflow;
    int m_rightVisualOverflow;
};

inline IntRect RenderOverflow::layoutOverflowRect() const
{
    return IntRect(m_leftLayoutOverflow, m_topLayoutOverflow, m_rightLayoutOverflow - m_leftLayoutOverflow, m_bottomLayoutOverflow - m_topLayoutOverflow);
}

inline IntRect RenderOverflow::visualOverflowRect() const
{
    return IntRect(m_leftVisualOverflow, m_topVisualOverflow, m_rightVisualOverflow - m_leftVisualOverflow, m_bottomVisualOverflow - m_topVisualOverflow);
}
/* paint机制 调用 */
inline IntRect RenderOverflow::visibleOverflowRect() const
{
    IntRect combinedRect(layoutOverflowRect());
    combinedRect.unite(visualOverflowRect());
    return combinedRect;
}

inline void RenderOverflow::move(int dx, int dy)
{
    m_topLayoutOverflow += dy;
    m_bottomLayoutOverflow += dy;
    m_leftLayoutOverflow += dx;
    m_rightLayoutOverflow += dx;
    
    m_topVisualOverflow += dy;
    m_bottomVisualOverflow += dy;
    m_leftVisualOverflow += dx;
    m_rightVisualOverflow += dx;
}
/* rect 的x,y坐标是相对去rect的cotaining box 的坐标 layout机制调用*/
inline void RenderOverflow::addLayoutOverflow(const IntRect& rect)
{
#ifdef PRINT_OVERFLOW
     printf("add layout overflow: rect x:%d y:%d width:%d height:%d\n",
	    rect.x(),rect.y(),rect.width(),rect.height());
     printf("orginal top:%d bottom:%d left:%d right:%d\n",m_topLayoutOverflow,
	    m_bottomLayoutOverflow,m_leftLayoutOverflow,m_rightLayoutOverflow);
#endif

     m_topLayoutOverflow = std::min(rect.y(), m_topLayoutOverflow);
     m_bottomLayoutOverflow = std::max(rect.bottom(), m_bottomLayoutOverflow);
     m_leftLayoutOverflow = std::min(rect.x(), m_leftLayoutOverflow);
     m_rightLayoutOverflow = std::max(rect.right(), m_rightLayoutOverflow);

#ifdef PRINT_OVERFLOW
     printf("current top:%d bottom:%d left:%d right:%d\n",m_topLayoutOverflow,
	    m_bottomLayoutOverflow,m_leftLayoutOverflow,m_rightLayoutOverflow);
#endif
}
/* rect 的x,y坐标是相对去rect的cotaining box 的坐标 layout机制调用*/
inline void RenderOverflow::addVisualOverflow(const IntRect& rect)
{
#ifdef PRINT_OVERFLOW
     printf("add visual overflow: rect x:%d y:%d width:%d height:%d\n",
	    rect.x(),rect.y(),rect.width(),rect.height());
     printf("orginal top:%d bottom:%d left:%d right:%d\n",m_topVisualOverflow,
	    m_bottomVisualOverflow,m_leftVisualOverflow,m_rightVisualOverflow);
#endif

    m_topVisualOverflow = std::min(rect.y(), m_topVisualOverflow);
    m_bottomVisualOverflow = std::max(rect.bottom(), m_bottomVisualOverflow);
    m_leftVisualOverflow = std::min(rect.x(), m_leftVisualOverflow);
    m_rightVisualOverflow = std::max(rect.right(), m_rightVisualOverflow);

#ifdef PRINT_OVERFLOW
    printf("current top:%d bottom:%d left:%d right:%d\n",m_topVisualOverflow,
	   m_bottomVisualOverflow,m_leftVisualOverflow,m_rightVisualOverflow);
#endif
}

inline void RenderOverflow::resetLayoutOverflow(const IntRect& rect)
{
    m_topLayoutOverflow = rect.y();
    m_bottomLayoutOverflow = rect.bottom();
    m_leftLayoutOverflow = rect.x();
    m_rightLayoutOverflow = rect.right();
}

} // namespace WebCore

#endif // RenderOverflow_h
