/*
 * Copyright (C) 2000 Lars Knoll (knoll@kde.org)
 * Copyright (C) 2003, 2004, 2006, 2007, 2008, 2009, 2010 Apple Inc. All right reserved.
 * Copyright (C) 2010 Google Inc. All rights reserved.
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

#ifndef InlineIterator_h
#define InlineIterator_h

#include "BidiRun.h"
#include "RenderBlock.h"
#include "RenderText.h"
#include <wtf/AlwaysInline.h>
#include <wtf/StdLibExtras.h>

namespace WebCore {

class InlineIterator {
public:
    InlineIterator()
        : block(0)
        , obj(0)
        , pos(0)
        , nextBreakablePosition(-1)
    {
    }

    InlineIterator(RenderBlock* b, RenderObject* o, unsigned p)
        : block(b)
        , obj(o)
        , pos(p)
        , nextBreakablePosition(-1)
    {
    }

    void increment(InlineBidiResolver* resolver = 0); /* 见函数实现注释 */
    bool atEnd() const;		/* 遍历完毕，此时obj=null */

    UChar current() const;	/* 返回当前pos在当前text的字符,只对isText起作用 */
    WTF::Unicode::Direction direction() const;

    RenderBlock* block;		/* 要遍历的block */
    RenderObject* obj;		/* 当前所指对象 */
    unsigned pos;
    int nextBreakablePosition;
};

inline bool operator==(const InlineIterator& it1, const InlineIterator& it2)
{
    return it1.pos == it2.pos && it1.obj == it2.obj;
}

inline bool operator!=(const InlineIterator& it1, const InlineIterator& it2)
{
    return it1.pos != it2.pos || it1.obj != it2.obj;
}
/* block:是line box的节点，里面包含了一些inline ,current:指向block中的其中一个inline节点,resolver:对文字进行bidi处理,skipInlines:是否忽略inline,endOfInlinePtr: 上个current是否是(找过的)inline */
static inline RenderObject* bidiNext(RenderBlock* block, RenderObject* current, InlineBidiResolver* resolver = 0, bool skipInlines = true, bool* endOfInlinePtr = 0)
{
    RenderObject* next = 0;	/* 指向current的下个inline */
    bool oldEndOfInline = endOfInlinePtr ? *endOfInlinePtr : false; /* 上个current是否是inline */
    bool endOfInline = false;	/* 当前current是不是inline */

    while (current) {
        next = 0;
        if (!oldEndOfInline && !current->isFloating() && !current->isReplaced() && !current->isPositioned() && !current->isText()) { /*上个节点不是inline节点且当前节点非float非replaced非positioned非text节点(非text节点，则说明它有子节点) */
            next = current->firstChild(); /* 找到第一个子节点(因为非text节点,所以一定有子节点) */
            if (next && resolver && next->isRenderInline()) { /* 进行resolver处理 */
                EUnicodeBidi ub = next->style()->unicodeBidi();
                if (ub != UBNormal) {
                    TextDirection dir = next->style()->direction();
                    WTF::Unicode::Direction d = (ub == Embed
                        ? (dir == RTL ? WTF::Unicode::RightToLeftEmbedding : WTF::Unicode::LeftToRightEmbedding)
                        : (dir == RTL ? WTF::Unicode::RightToLeftOverride : WTF::Unicode::LeftToRightOverride));
                    resolver->embed(d);
                }
            }
        }

        if (!next) { /* 如果上步没有得到next( current是text节点,或则curren是float|positioned|replaced) */
            if (!skipInlines && !oldEndOfInline && current->isRenderInline()) { /* 如果不忽略inline,且之前找到的(上个current)不是inline,且当前current是inline */
                next = current;
                endOfInline = true;
                break;
            }

            while (current && current != block) { /* 当前节点存在且不等于block */
                if (resolver && current->isRenderInline() && current->style()->unicodeBidi() != UBNormal)
                    resolver->embed(WTF::Unicode::PopDirectionalFormat);

                next = current->nextSibling(); /* 找到下个兄弟节点 */
                if (next) {		       /* 如果存在下个兄弟节点,则找到 */
                    if (resolver && next->isRenderInline()) { /* 进行resolver处理 */
                        EUnicodeBidi ub = next->style()->unicodeBidi();
                        if (ub != UBNormal) {
                            TextDirection dir = next->style()->direction();
                            WTF::Unicode::Direction d = (ub == Embed
                                ? (dir == RTL ? WTF::Unicode::RightToLeftEmbedding: WTF::Unicode::LeftToRightEmbedding)
                                : (dir == RTL ? WTF::Unicode::RightToLeftOverride : WTF::Unicode::LeftToRightOverride));
                            resolver->embed(d);
                        }
                    }
                    break;	/* 退出循环 */
                }
		/* 如果没有了下个兄弟节点 */
                current = current->parent(); /* 则使current指向其父节点 */
                if (!skipInlines && current && current != block && current->isRenderInline()) { /* 如果不忽略inline节点,current存在,且current不等于block,且current是inline */
                    next = current; /* 则让next等于current */
                    endOfInline = true; /* 最后找到的next是Inline */
                    break;
                }
            }
        }

        if (!next) /* 此时current == block,inline扫描完毕 */
            break;

        if (next->isText() || next->isFloating() || next->isReplaced() || next->isPositioned()
            || ((!skipInlines || !next->firstChild()) // Always return EMPTY inlines.
                && next->isRenderInline()))	     
            break;		/* 找到了next ,退出循环 */
        current = next;
    }

    if (endOfInlinePtr)	/*endOfInlinePtr指针不为空  */
        *endOfInlinePtr = endOfInline; /* endOfInlinePtr符上新值 */

    return next; /* 返回next */
}

static inline RenderObject* bidiFirst(RenderBlock* block, InlineBidiResolver* resolver, bool skipInlines = true)
{
    if (!block->firstChild())	/* no first child return zero */
        return 0;
    
    RenderObject* o = block->firstChild(); /* 第一个可见的孩子 */
    if (o->isRenderInline()) {		   /* if o is inline */
        if (resolver) {			   /* resolver处理 */
            EUnicodeBidi ub = o->style()->unicodeBidi();
            if (ub != UBNormal) {
                TextDirection dir = o->style()->direction();
                WTF::Unicode::Direction d = (ub == Embed
                    ? (dir == RTL ? WTF::Unicode::RightToLeftEmbedding : WTF::Unicode::LeftToRightEmbedding)
                    : (dir == RTL ? WTF::Unicode::RightToLeftOverride : WTF::Unicode::LeftToRightOverride));
                resolver->embed(d);
            }
        }
        if (skipInlines && o->firstChild()) /* 如果忽略inline,且该line(which is o)有孩子 */
            o = bidiNext(block, o, resolver, skipInlines); /* 则找下个节点 */
        else {				   /* 如果不忽略inline,则返回o  */
            // Never skip empty inlines.
            if (resolver)
                resolver->commitExplicitEmbedding();
            return o; 		/* 返回inline */
        }
    }

    if (o && !o->isText() && !o->isReplaced() && !o->isFloating() && !o->isPositioned())
        o = bidiNext(block, o, resolver, skipInlines);
    /* 到此,o 非inline,且是text|replaced|floation|positioned，但也有可能是空 */
    if (resolver)
        resolver->commitExplicitEmbedding();
    return o;			/* 返回非inline */
}

inline void InlineIterator::increment(InlineBidiResolver* resolver)
{
    if (!obj)
        return;
    if (obj->isText()) {	/* 如果当前遍历对象为text */
        pos++;/* 增加pos(当前字符位置) */
        if (pos >= toRenderText(obj)->textLength()) { /* 如果pos到达text的length */
            obj = bidiNext(block, obj, resolver);     /* 则遍历到下个非inline对象 */
            pos = 0;				      /* pos重新置零 */
            nextBreakablePosition = -1;
        }
    } else {			/* 如果当前遍历对象不为text,则直接到下个对象 */
        obj = bidiNext(block, obj, resolver);
        pos = 0;
        nextBreakablePosition = -1;
    }
}

inline bool InlineIterator::atEnd() const
{
    return !obj;
}

inline UChar InlineIterator::current() const
{
    if (!obj || !obj->isText())
        return 0;
    /* 到这里仅当obj存在且obj isText */
    RenderText* text = toRenderText(obj);
    if (pos >= text->textLength())
        return 0;

    return text->characters()[pos];
}

ALWAYS_INLINE WTF::Unicode::Direction InlineIterator::direction() const
{
    if (UChar c = current())
        return WTF::Unicode::direction(c);

    if (obj && obj->isListMarker())
        return obj->style()->direction() == LTR ? WTF::Unicode::LeftToRight : WTF::Unicode::RightToLeft;

    return WTF::Unicode::OtherNeutral;
}

template<>
inline void InlineBidiResolver::increment()
{
    current.increment(this);
}

template <>
inline void InlineBidiResolver::appendRun()
{
    if (!emptyRun && !eor.atEnd()) {
        int start = sor.pos;
        RenderObject *obj = sor.obj;
        while (obj && obj != eor.obj && obj != endOfLine.obj) {
            RenderBlock::appendRunsForObject(start, obj->length(), obj, *this);        
            start = 0;
            obj = bidiNext(sor.block, obj);
        }
        if (obj) {
            unsigned pos = obj == eor.obj ? eor.pos : UINT_MAX;
            if (obj == endOfLine.obj && endOfLine.pos <= pos) {
                reachedEndOfLine = true;
                pos = endOfLine.pos;
            }
            // It's OK to add runs for zero-length RenderObjects, just don't make the run larger than it should be
            int end = obj->length() ? pos+1 : 0;
            RenderBlock::appendRunsForObject(start, end, obj, *this);
        }
        
        eor.increment();
        sor = eor;
    }

    m_direction = WTF::Unicode::OtherNeutral;
    m_status.eor = WTF::Unicode::OtherNeutral;
}

}

#endif // InlineIterator_h
