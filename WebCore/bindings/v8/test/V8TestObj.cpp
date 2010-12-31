/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

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
    the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.
*/
#include "config.h"
#include "RuntimeEnabledFeatures.h"
#include "V8Proxy.h"
#include "V8Binding.h"
#include "V8BindingState.h"
#include "V8DOMWrapper.h"
#include "V8IsolatedContext.h"

#undef LOG

#include "ExceptionCode.h"
#include "V8TestObj.h"
#include "wtf/GetPtr.h"
#include "wtf/RefCounted.h"
#include "wtf/RefPtr.h"

namespace WebCore {

WrapperTypeInfo V8TestObj::info = { V8TestObj::GetTemplate, V8TestObj::derefObject, 0 };

namespace TestObjInternal {

template <typename T> void V8_USE(T) { }

static v8::Handle<v8::Value> readOnlyIntAttrAttrGetter(v8::Local<v8::String> name, const v8::AccessorInfo& info)
{
    INC_STATS("DOM.TestObj.readOnlyIntAttr._get");
    TestObj* imp = V8TestObj::toNative(info.Holder());
    return v8::Integer::New(imp->readOnlyIntAttr());
}

static v8::Handle<v8::Value> readOnlyStringAttrAttrGetter(v8::Local<v8::String> name, const v8::AccessorInfo& info)
{
    INC_STATS("DOM.TestObj.readOnlyStringAttr._get");
    TestObj* imp = V8TestObj::toNative(info.Holder());
    return v8String(imp->readOnlyStringAttr());
}

static v8::Handle<v8::Value> readOnlyTestObjAttrAttrGetter(v8::Local<v8::String> name, const v8::AccessorInfo& info)
{
    INC_STATS("DOM.TestObj.readOnlyTestObjAttr._get");
    TestObj* imp = V8TestObj::toNative(info.Holder());
    RefPtr<TestObj> result = imp->readOnlyTestObjAttr();
    v8::Handle<v8::Value> wrapper = result.get() ? getDOMObjectMap().get(result.get()) : v8::Handle<v8::Value>();
    if (wrapper.IsEmpty()) {
        wrapper = toV8(result.get());
        if (!wrapper.IsEmpty())
            V8DOMWrapper::setHiddenReference(info.Holder(), wrapper);
    }
    return wrapper;
}

static v8::Handle<v8::Value> intAttrAttrGetter(v8::Local<v8::String> name, const v8::AccessorInfo& info)
{
    INC_STATS("DOM.TestObj.intAttr._get");
    TestObj* imp = V8TestObj::toNative(info.Holder());
    return v8::Integer::New(imp->intAttr());
}

static void intAttrAttrSetter(v8::Local<v8::String> name, v8::Local<v8::Value> value, const v8::AccessorInfo& info)
{
    INC_STATS("DOM.TestObj.intAttr._set");
    TestObj* imp = V8TestObj::toNative(info.Holder());
    int v = toInt32(value);
    imp->setIntAttr(v);
    return;
}

static v8::Handle<v8::Value> stringAttrAttrGetter(v8::Local<v8::String> name, const v8::AccessorInfo& info)
{
    INC_STATS("DOM.TestObj.stringAttr._get");
    TestObj* imp = V8TestObj::toNative(info.Holder());
    return v8String(imp->stringAttr());
}

static void stringAttrAttrSetter(v8::Local<v8::String> name, v8::Local<v8::Value> value, const v8::AccessorInfo& info)
{
    INC_STATS("DOM.TestObj.stringAttr._set");
    TestObj* imp = V8TestObj::toNative(info.Holder());
    V8Parameter<> v = value;
    imp->setStringAttr(v);
    return;
}

static v8::Handle<v8::Value> testObjAttrAttrGetter(v8::Local<v8::String> name, const v8::AccessorInfo& info)
{
    INC_STATS("DOM.TestObj.testObjAttr._get");
    TestObj* imp = V8TestObj::toNative(info.Holder());
    return toV8(imp->testObjAttr());
}

static void testObjAttrAttrSetter(v8::Local<v8::String> name, v8::Local<v8::Value> value, const v8::AccessorInfo& info)
{
    INC_STATS("DOM.TestObj.testObjAttr._set");
    TestObj* imp = V8TestObj::toNative(info.Holder());
    TestObj* v = V8TestObj::HasInstance(value) ? V8TestObj::toNative(v8::Handle<v8::Object>::Cast(value)) : 0;
    imp->setTestObjAttr(WTF::getPtr(v));
    return;
}

static v8::Handle<v8::Value> attrWithExceptionAttrGetter(v8::Local<v8::String> name, const v8::AccessorInfo& info)
{
    INC_STATS("DOM.TestObj.attrWithException._get");
    TestObj* imp = V8TestObj::toNative(info.Holder());
    return v8::Integer::New(imp->attrWithException());
}

static void attrWithExceptionAttrSetter(v8::Local<v8::String> name, v8::Local<v8::Value> value, const v8::AccessorInfo& info)
{
    INC_STATS("DOM.TestObj.attrWithException._set");
    TestObj* imp = V8TestObj::toNative(info.Holder());
    int v = toInt32(value);
    imp->setAttrWithException(v);
    return;
}

static v8::Handle<v8::Value> attrWithSetterExceptionAttrGetter(v8::Local<v8::String> name, const v8::AccessorInfo& info)
{
    INC_STATS("DOM.TestObj.attrWithSetterException._get");
    TestObj* imp = V8TestObj::toNative(info.Holder());
    return v8::Integer::New(imp->attrWithSetterException());
}

static void attrWithSetterExceptionAttrSetter(v8::Local<v8::String> name, v8::Local<v8::Value> value, const v8::AccessorInfo& info)
{
    INC_STATS("DOM.TestObj.attrWithSetterException._set");
    TestObj* imp = V8TestObj::toNative(info.Holder());
    int v = toInt32(value);
    imp->setAttrWithSetterException(v);
    return;
}

static v8::Handle<v8::Value> attrWithGetterExceptionAttrGetter(v8::Local<v8::String> name, const v8::AccessorInfo& info)
{
    INC_STATS("DOM.TestObj.attrWithGetterException._get");
    TestObj* imp = V8TestObj::toNative(info.Holder());
    return v8::Integer::New(imp->attrWithGetterException());
}

static void attrWithGetterExceptionAttrSetter(v8::Local<v8::String> name, v8::Local<v8::Value> value, const v8::AccessorInfo& info)
{
    INC_STATS("DOM.TestObj.attrWithGetterException._set");
    TestObj* imp = V8TestObj::toNative(info.Holder());
    int v = toInt32(value);
    imp->setAttrWithGetterException(v);
    return;
}

static v8::Handle<v8::Value> voidMethodCallback(const v8::Arguments& args) {
    INC_STATS("DOM.TestObj.voidMethod");
    TestObj* imp = V8TestObj::toNative(args.Holder());
    imp->voidMethod();
    return v8::Handle<v8::Value>();
}

static v8::Handle<v8::Value> voidMethodWithArgsCallback(const v8::Arguments& args) {
    INC_STATS("DOM.TestObj.voidMethodWithArgs");
    TestObj* imp = V8TestObj::toNative(args.Holder());
    int intArg = toInt32(args[0]);
    V8Parameter<> strArg = args[1];
    TestObj* objArg = V8TestObj::HasInstance(args[2]) ? V8TestObj::toNative(v8::Handle<v8::Object>::Cast(args[2])) : 0;
    imp->voidMethodWithArgs(intArg, strArg, objArg);
    return v8::Handle<v8::Value>();
}

static v8::Handle<v8::Value> intMethodCallback(const v8::Arguments& args) {
    INC_STATS("DOM.TestObj.intMethod");
    TestObj* imp = V8TestObj::toNative(args.Holder());
    return v8::Integer::New(imp->intMethod());
}

static v8::Handle<v8::Value> intMethodWithArgsCallback(const v8::Arguments& args) {
    INC_STATS("DOM.TestObj.intMethodWithArgs");
    TestObj* imp = V8TestObj::toNative(args.Holder());
    int intArg = toInt32(args[0]);
    V8Parameter<> strArg = args[1];
    TestObj* objArg = V8TestObj::HasInstance(args[2]) ? V8TestObj::toNative(v8::Handle<v8::Object>::Cast(args[2])) : 0;
    return v8::Integer::New(imp->intMethodWithArgs(intArg, strArg, objArg));
}

static v8::Handle<v8::Value> objMethodCallback(const v8::Arguments& args) {
    INC_STATS("DOM.TestObj.objMethod");
    TestObj* imp = V8TestObj::toNative(args.Holder());
    return toV8(imp->objMethod());
}

static v8::Handle<v8::Value> objMethodWithArgsCallback(const v8::Arguments& args) {
    INC_STATS("DOM.TestObj.objMethodWithArgs");
    TestObj* imp = V8TestObj::toNative(args.Holder());
    int intArg = toInt32(args[0]);
    V8Parameter<> strArg = args[1];
    TestObj* objArg = V8TestObj::HasInstance(args[2]) ? V8TestObj::toNative(v8::Handle<v8::Object>::Cast(args[2])) : 0;
    return toV8(imp->objMethodWithArgs(intArg, strArg, objArg));
}

static v8::Handle<v8::Value> methodWithExceptionCallback(const v8::Arguments& args) {
    INC_STATS("DOM.TestObj.methodWithException");
    TestObj* imp = V8TestObj::toNative(args.Holder());
    ExceptionCode ec = 0;
    {
    imp->methodWithException(ec);
    if (UNLIKELY(ec)) goto fail;
    return v8::Handle<v8::Value>();
    }
    fail:
    V8Proxy::setDOMException(ec);
    return v8::Handle<v8::Value>();
}

static v8::Handle<v8::Value> methodWithOptionalArgCallback(const v8::Arguments& args) {
    INC_STATS("DOM.TestObj.methodWithOptionalArg");
    TestObj* imp = V8TestObj::toNative(args.Holder());
    if (args.Length() <= 0) {
        imp->methodWithOptionalArg();
        return v8::Handle<v8::Value>();
    }
    int opt = toInt32(args[0]);
    imp->methodWithOptionalArg(opt);
    return v8::Handle<v8::Value>();
}

static v8::Handle<v8::Value> methodWithNonOptionalArgAndOptionalArgCallback(const v8::Arguments& args) {
    INC_STATS("DOM.TestObj.methodWithNonOptionalArgAndOptionalArg");
    TestObj* imp = V8TestObj::toNative(args.Holder());
    int nonOpt = toInt32(args[0]);
    if (args.Length() <= 1) {
        imp->methodWithNonOptionalArgAndOptionalArg(nonOpt);
        return v8::Handle<v8::Value>();
    }
    int opt = toInt32(args[1]);
    imp->methodWithNonOptionalArgAndOptionalArg(nonOpt, opt);
    return v8::Handle<v8::Value>();
}

static v8::Handle<v8::Value> methodWithNonOptionalArgAndTwoOptionalArgsCallback(const v8::Arguments& args) {
    INC_STATS("DOM.TestObj.methodWithNonOptionalArgAndTwoOptionalArgs");
    TestObj* imp = V8TestObj::toNative(args.Holder());
    int nonOpt = toInt32(args[0]);
    if (args.Length() <= 1) {
        imp->methodWithNonOptionalArgAndTwoOptionalArgs(nonOpt);
        return v8::Handle<v8::Value>();
    }
    int opt1 = toInt32(args[1]);
    int opt2 = toInt32(args[2]);
    imp->methodWithNonOptionalArgAndTwoOptionalArgs(nonOpt, opt1, opt2);
    return v8::Handle<v8::Value>();
}

} // namespace TestObjInternal

static const BatchedAttribute TestObj_attrs[] = {
    {
        // Attribute 'readOnlyIntAttr' (Type: 'readonly attribute' ExtAttr: '')
        "readOnlyIntAttr",
        TestObjInternal::readOnlyIntAttrAttrGetter,
        0,
        0 /* no data */,
        static_cast<v8::AccessControl>(v8::DEFAULT),
        static_cast<v8::PropertyAttribute>(v8::None),
        0 /* on instance */
    },
    {
        // Attribute 'readOnlyStringAttr' (Type: 'readonly attribute' ExtAttr: '')
        "readOnlyStringAttr",
        TestObjInternal::readOnlyStringAttrAttrGetter,
        0,
        0 /* no data */,
        static_cast<v8::AccessControl>(v8::DEFAULT),
        static_cast<v8::PropertyAttribute>(v8::None),
        0 /* on instance */
    },
    {
        // Attribute 'readOnlyTestObjAttr' (Type: 'readonly attribute' ExtAttr: '')
        "readOnlyTestObjAttr",
        TestObjInternal::readOnlyTestObjAttrAttrGetter,
        0,
        0 /* no data */,
        static_cast<v8::AccessControl>(v8::DEFAULT),
        static_cast<v8::PropertyAttribute>(v8::None),
        0 /* on instance */
    },
    {
        // Attribute 'intAttr' (Type: 'attribute' ExtAttr: '')
        "intAttr",
        TestObjInternal::intAttrAttrGetter,
        TestObjInternal::intAttrAttrSetter,
        0 /* no data */,
        static_cast<v8::AccessControl>(v8::DEFAULT),
        static_cast<v8::PropertyAttribute>(v8::None),
        0 /* on instance */
    },
    {
        // Attribute 'stringAttr' (Type: 'attribute' ExtAttr: '')
        "stringAttr",
        TestObjInternal::stringAttrAttrGetter,
        TestObjInternal::stringAttrAttrSetter,
        0 /* no data */,
        static_cast<v8::AccessControl>(v8::DEFAULT),
        static_cast<v8::PropertyAttribute>(v8::None),
        0 /* on instance */
    },
    {
        // Attribute 'testObjAttr' (Type: 'attribute' ExtAttr: '')
        "testObjAttr",
        TestObjInternal::testObjAttrAttrGetter,
        TestObjInternal::testObjAttrAttrSetter,
        0 /* no data */,
        static_cast<v8::AccessControl>(v8::DEFAULT),
        static_cast<v8::PropertyAttribute>(v8::None),
        0 /* on instance */
    },
    {
        // Attribute 'attrWithException' (Type: 'attribute' ExtAttr: '')
        "attrWithException",
        TestObjInternal::attrWithExceptionAttrGetter,
        TestObjInternal::attrWithExceptionAttrSetter,
        0 /* no data */,
        static_cast<v8::AccessControl>(v8::DEFAULT),
        static_cast<v8::PropertyAttribute>(v8::None),
        0 /* on instance */
    },
    {
        // Attribute 'attrWithSetterException' (Type: 'attribute' ExtAttr: '')
        "attrWithSetterException",
        TestObjInternal::attrWithSetterExceptionAttrGetter,
        TestObjInternal::attrWithSetterExceptionAttrSetter,
        0 /* no data */,
        static_cast<v8::AccessControl>(v8::DEFAULT),
        static_cast<v8::PropertyAttribute>(v8::None),
        0 /* on instance */
    },
    {
        // Attribute 'attrWithGetterException' (Type: 'attribute' ExtAttr: '')
        "attrWithGetterException",
        TestObjInternal::attrWithGetterExceptionAttrGetter,
        TestObjInternal::attrWithGetterExceptionAttrSetter,
        0 /* no data */,
        static_cast<v8::AccessControl>(v8::DEFAULT),
        static_cast<v8::PropertyAttribute>(v8::None),
        0 /* on instance */
    },
    {
        // Attribute 'customAttr' (Type: 'attribute' ExtAttr: 'Custom')
        "customAttr",
        V8TestObj::customAttrAccessorGetter,
        V8TestObj::customAttrAccessorSetter,
        0 /* no data */,
        static_cast<v8::AccessControl>(v8::DEFAULT),
        static_cast<v8::PropertyAttribute>(v8::None),
        0 /* on instance */
    },
};
static const BatchedCallback TestObj_callbacks[] = {
  {"voidMethod", TestObjInternal::voidMethodCallback},
  {"intMethod", TestObjInternal::intMethodCallback},
  {"objMethod", TestObjInternal::objMethodCallback},
  {"methodWithException", TestObjInternal::methodWithExceptionCallback},
  {"customMethod", V8TestObj::customMethodCallback},
  {"customMethodWithArgs", V8TestObj::customMethodWithArgsCallback},
  {"methodWithOptionalArg", TestObjInternal::methodWithOptionalArgCallback},
  {"methodWithNonOptionalArgAndOptionalArg", TestObjInternal::methodWithNonOptionalArgAndOptionalArgCallback},
  {"methodWithNonOptionalArgAndTwoOptionalArgs", TestObjInternal::methodWithNonOptionalArgAndTwoOptionalArgsCallback},
};
static v8::Persistent<v8::FunctionTemplate> ConfigureV8TestObjTemplate(v8::Persistent<v8::FunctionTemplate> desc)
{
    v8::Local<v8::Signature> default_signature = configureTemplate(desc, "TestObj", v8::Persistent<v8::FunctionTemplate>(), V8TestObj::internalFieldCount,
        TestObj_attrs, sizeof(TestObj_attrs)/sizeof(*TestObj_attrs),
        TestObj_callbacks, sizeof(TestObj_callbacks)/sizeof(*TestObj_callbacks));
    v8::Local<v8::ObjectTemplate> instance = desc->InstanceTemplate();
    v8::Local<v8::ObjectTemplate> proto = desc->PrototypeTemplate();
    

    // Custom Signature 'voidMethodWithArgs'
    const int voidMethodWithArgs_argc = 3;
    v8::Handle<v8::FunctionTemplate> voidMethodWithArgs_argv[voidMethodWithArgs_argc] = { v8::Handle<v8::FunctionTemplate>(), v8::Handle<v8::FunctionTemplate>(), V8TestObj::GetRawTemplate() };
    v8::Handle<v8::Signature> voidMethodWithArgs_signature = v8::Signature::New(desc, voidMethodWithArgs_argc, voidMethodWithArgs_argv);
    proto->Set(v8::String::New("voidMethodWithArgs"), v8::FunctionTemplate::New(TestObjInternal::voidMethodWithArgsCallback, v8::Handle<v8::Value>(), voidMethodWithArgs_signature));

    // Custom Signature 'intMethodWithArgs'
    const int intMethodWithArgs_argc = 3;
    v8::Handle<v8::FunctionTemplate> intMethodWithArgs_argv[intMethodWithArgs_argc] = { v8::Handle<v8::FunctionTemplate>(), v8::Handle<v8::FunctionTemplate>(), V8TestObj::GetRawTemplate() };
    v8::Handle<v8::Signature> intMethodWithArgs_signature = v8::Signature::New(desc, intMethodWithArgs_argc, intMethodWithArgs_argv);
    proto->Set(v8::String::New("intMethodWithArgs"), v8::FunctionTemplate::New(TestObjInternal::intMethodWithArgsCallback, v8::Handle<v8::Value>(), intMethodWithArgs_signature));

    // Custom Signature 'objMethodWithArgs'
    const int objMethodWithArgs_argc = 3;
    v8::Handle<v8::FunctionTemplate> objMethodWithArgs_argv[objMethodWithArgs_argc] = { v8::Handle<v8::FunctionTemplate>(), v8::Handle<v8::FunctionTemplate>(), V8TestObj::GetRawTemplate() };
    v8::Handle<v8::Signature> objMethodWithArgs_signature = v8::Signature::New(desc, objMethodWithArgs_argc, objMethodWithArgs_argv);
    proto->Set(v8::String::New("objMethodWithArgs"), v8::FunctionTemplate::New(TestObjInternal::objMethodWithArgsCallback, v8::Handle<v8::Value>(), objMethodWithArgs_signature));

    // Custom toString template
    desc->Set(getToStringName(), getToStringTemplate());
    return desc;
}

v8::Persistent<v8::FunctionTemplate> V8TestObj::GetRawTemplate()
{
    static v8::Persistent<v8::FunctionTemplate> V8TestObj_raw_cache_ = createRawTemplate();
    return V8TestObj_raw_cache_;
}

v8::Persistent<v8::FunctionTemplate> V8TestObj::GetTemplate()
{
    static v8::Persistent<v8::FunctionTemplate> V8TestObj_cache_ = ConfigureV8TestObjTemplate(GetRawTemplate());
    return V8TestObj_cache_;
}

TestObj* V8TestObj::toNative(v8::Handle<v8::Object> object)
{
    return reinterpret_cast<TestObj*>(object->GetPointerFromInternalField(v8DOMWrapperObjectIndex));
}

bool V8TestObj::HasInstance(v8::Handle<v8::Value> value)
{
    return GetRawTemplate()->HasInstance(value);
}


v8::Handle<v8::Object> V8TestObj::wrap(TestObj* impl)
{
    v8::Handle<v8::Object> wrapper;
    V8Proxy* proxy = 0;
    wrapper = getDOMObjectMap().get(impl);
    if (!wrapper.IsEmpty())
        return wrapper;
    wrapper = V8DOMWrapper::instantiateV8Object(proxy, &info, impl);
    if (wrapper.IsEmpty())
        return wrapper;

    impl->ref();
    getDOMObjectMap().set(impl, v8::Persistent<v8::Object>::New(wrapper));
    return wrapper;
}

v8::Handle<v8::Value> toV8(PassRefPtr<TestObj > impl)
{
    return toV8(impl.get());
}

v8::Handle<v8::Value> toV8(TestObj* impl)
{
    if (!impl)
        return v8::Null();
    return V8TestObj::wrap(impl);
}

void V8TestObj::derefObject(void* object)
{
    static_cast<TestObj*>(object)->deref();
}

} // namespace WebCore
