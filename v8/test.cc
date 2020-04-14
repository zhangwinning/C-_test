#include <iostream>
#include "include/v8.h"
#include "include/libplatform/libplatform.h"

using namespace std;
using namespace v8;

int main(int argc, char *argv[]) {
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
    Local<FunctionTemplate> constructor = Local<FunctionTemplate>();
    Local<ObjectTemplate> ot = ObjectTemplate::New(isolate_, constructor);


    const char *prop_name = "prop_name";
    const char *prop_value = "prop_value";
    Local<Name> name = String::NewFromUtf8(isolate_, prop_name, NewStringType::kNormal).ToLocalChecked();
    Local<Data> value = String::NewFromUtf8(isolate_, prop_value, NewStringType::kNormal).ToLocalChecked();
    ot->Set(name, value, PropertyAttribute::None);

    Handle<Context> context = Context::New(isolate_, nullptr, ot);
    MaybeLocal<Object> maybe_instance = ot->NewInstance(context);
    Local<Object> obj = maybe_instance.ToLocalChecked();

    MaybeLocal<Array> maybe_names = obj->GetPropertyNames(context);
    Local<Array> names = maybe_names.ToLocalChecked();

    int a = static_cast<int>(names->Length());


    Local<Value> name_from_array = names->Get(context, 0).ToLocalChecked();
    String::Utf8Value utf8_name{isolate_, name_from_array};

// Verify the value is correct.
    Local<Value> val = obj->GetRealNamedProperty(context, name).ToLocalChecked();
    bool b = val->IsName();
    String::Utf8Value utf8_value{isolate_, val};

    std::cout << "hello"  "    " << a << b << endl;

    cout << *utf8_value << endl;

    cout << *utf8_name << endl;
}