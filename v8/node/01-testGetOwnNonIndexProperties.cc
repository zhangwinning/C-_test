#include <stdio.h>
#include <iostream>
#include "include/v8.h"
#include "include/libplatform/libplatform.h"

using namespace std;
using namespace v8;


void GetOwnNonIndexProperties(const FunctionCallbackInfo<Value>& args) {
//    Environment* env = Environment::GetCurrent(args);

//    printf("===>", args[0]);
    Isolate *isolate = args.GetIsolate();

//    Local<Context> contex = isolate->context();
//    printf("test");

    // Local<Array> properties;
    cout << "data:" << endl;

    // properties.push(100);

//    for(let i = 0; i < properties.lenght; i++) {
//
//    }
    // cout << properties << endl;
    // Local<Object> object = args[0].As<Object>();

    // cout << typeid(object).name() << endl;
//    printf("isolate:", isolate);

PropertyFilter filter =
    static_cast<PropertyFilter>(args[1].As<Uint32>()->Value());

     // args.GetReturnValue().Set(properties);
}
int main(int argc, char* argv[]) {
//    GetOwnNonIndexProperties();
    printf("hello world");
    cout << argv << "   " << *argv << "    " << argv[0] << endl;
    V8::InitializeICUDefaultLocation(argv[0]);
    V8::InitializeExternalStartupData(argv[0]);
    unique_ptr<v8::Platform> platform = v8::platform::NewDefaultPlatform();
    V8::InitializePlatform(platform.get());
    V8::Initialize();


    Isolate::CreateParams create_params;
    create_params.array_buffer_allocator = ArrayBuffer::Allocator::NewDefaultAllocator();
    Isolate *isolate_ = Isolate::New(create_params);
    const HandleScope handle_scope(isolate_);
    Handle<Context> context = Context::New(isolate_);
    Context::Scope context_scope(context);

    Local<Value> data = String::NewFromUtf8(isolate_, "some info", NewStringType::kNormal).ToLocalChecked();

    Local<FunctionTemplate> ft = FunctionTemplate::New(isolate_,
            GetOwnNonIndexProperties, data);
    cout << "data:" << (*data) << endl;

    Local<Function> function = ft->GetFunction(context).ToLocalChecked();

    Local<Object> recv = Object::New(isolate_);
    int argc1 = 0;

    MaybeLocal<Value> ret = function->Call(context, recv, argc1, nullptr);
}