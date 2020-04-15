#include <iostream>
#include "include/v8.h"
#include "include/libplatform/libplatform.h"

using namespace std;
using namespace v8;

void function_callback(const FunctionCallbackInfo<Value> &info) {
    Isolate *isolate = info.GetIsolate();
    std::cout << "function_callback args= " << info.Length() << '\n';

    // If the function was called using the new operator the property
    // new.target(NewTarget) will be set.
    Local<Value> new_target_value = info.NewTarget();
    if (new_target_value.IsEmpty()) {
        std::cout << "new_target_value is undefined: " << new_target_value->IsUndefined() << '\n';
    }
    // This is the receiver passed as the second argument to the Call function,
    // which is like the this.
    Local<Object> receiver = info.This();
    Local<Name> name = String::NewFromUtf8(isolate, "nr", NewStringType::kNormal).ToLocalChecked();
    Local<Value> nr_local = receiver->GetRealNamedProperty(isolate->GetCurrentContext(), name).ToLocalChecked();
    Local<Number> nr = nr_local->ToNumber(isolate->GetCurrentContext()).ToLocalChecked();

    Local<Object> holder = info.Holder();

    ReturnValue<Value> return_value = info.GetReturnValue();
    double nr2 = nr->Value() + 2;
    cout << "nrc: " << nr->Value() << endl;

//    cout << "====> "<< *String::Utf8Value(isolate, info.Data()) << endl;
    return_value.Set(nr2);
//    EXPECT_STREQ(*String::Utf8Value(isolate, info.Data()), "some info");
}

int main(int argc, char *argv[]) {
//    cout << argv << "   " << *argv << "    " << argv[0] << endl;
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

    cout << "data:" << (*data) << endl;
    Local<FunctionTemplate> ft = FunctionTemplate::New(isolate_, function_callback, data);
    Local<Function> function = ft->GetFunction(context).ToLocalChecked();
    Local<String> func_name = String::NewFromUtf8(isolate_, "SomeFunc", NewStringType::kNormal).ToLocalChecked();
    function->SetName(func_name);
    Local<Value> prototype = function->GetPrototype();

    cout << "=========>" << *prototype << endl;


    Local<Object> recv = Object::New(isolate_);
    Local<Name> name = String::NewFromUtf8(isolate_, "nr", NewStringType::kNormal).ToLocalChecked();
    Local<Number> value = Number::New(isolate_, 18);
    recv->Set(context, name, value).Check();

    int argc1 = 0;
    Local<Value> argv1[] = {};
    MaybeLocal<Value> ret = function->Call(context, recv, argc1, nullptr);
    if (!ret.IsEmpty()) {
        Local<Number> nr = ret.ToLocalChecked()->ToNumber(context).ToLocalChecked();
        cout << nr->Value() << endl;
    }

//    i::RootsTable roots_table = i_isolate->roots_table();
//    i::Heap* heap = i_isolate->heap();
}