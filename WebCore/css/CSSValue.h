/*
 * (C) 1999-2003 Lars Knoll (knoll@kde.org)
 * Copyright (C) 2004, 2005, 2006, 2007, 2008 Apple Inc. All rights reserved.
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
 */

#ifndef CSSValue_h
#define CSSValue_h

#include "StyleBase.h"

#include "CSSParserValues.h"
#include "KURLHash.h"
#include <wtf/ListHashSet.h>
#include <wtf/RefPtr.h>

namespace WebCore {

class CSSStyleSheet;

typedef int ExceptionCode;
/* CSSValue代表一个属性的值 */
class CSSValue : public RefCounted<CSSValue> {
public:
    // FIXME: Change name to Type.
    enum UnitTypes {
        CSS_INHERIT = 0,
        CSS_PRIMITIVE_VALUE = 1,
        CSS_VALUE_LIST = 2,
        CSS_CUSTOM = 3,
        CSS_INITIAL = 4
    };

    virtual ~CSSValue() { }

    // FIXME: Change this to return UnitTypes.
    virtual unsigned short cssValueType() const { return CSS_CUSTOM; }

    virtual String cssText() const = 0;
    void setCssText(const String&, ExceptionCode&) { } // FIXME: Not implemented.

    virtual bool isFontValue() const { return false; } /* 字体值 */
    virtual bool isImageGeneratorValue() const { return false; }
    virtual bool isImageValue() const { return false; } /* 图像值 */
    virtual bool isImplicitInitialValue() const { return false; }
    virtual bool isPrimitiveValue() const { return false; }
    virtual bool isTimingFunctionValue() const { return false; }
    virtual bool isValueList() const { return false; } /* 是值列表吗?代表一个属性有多个值的情况 */
    virtual bool isWebKitCSSTransformValue() const { return false; }

#if ENABLE(SVG)
    virtual bool isSVGColor() const { return false; }
    virtual bool isSVGPaint() const { return false; }
#endif

    virtual bool isVariableDependentValue() const { return false; }
    virtual CSSParserValue parserValue() const { ASSERT_NOT_REACHED(); return CSSParserValue(); }

    virtual void addSubresourceStyleURLs(ListHashSet<KURL>&, const CSSStyleSheet*) { }
};

} // namespace WebCore

#endif // CSSValue_h
