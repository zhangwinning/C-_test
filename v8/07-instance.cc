// source code https://github.com/danbev/learning-v8/blob/master/instances.cc
#include <iostream>

#include "include/v8.h"
#include "include/libplatform/libplatform.h"

using namespace std;
using namespace v8;

class Person {
private:
    std::string name_;

public:
    Person(std::string name) : name_(name) {
    };

    string name() const {
        return name_;
    }

};

void NewPerson(const FunctionCallbackInfo<Value> &args) {
    Isolate *isolate = args.GetIsolate();
    String::Utf8Value str{isolate, args[0]};
    Person *p = new Person(*str);
    std::cout << "Created new Person(" << p->name() << ")" << std::endl;
    Local<Object> self = args.Holder();
//  设置快属性 https://time.geekbang.org/column/article/213250，我觉的这个索引值是 0。是数字，应该设置的是快属性。
//  其实我我觉的这里的设置就是在对象上 self 这个实例上设置一个值。
    self->SetAlignedPointerInInternalField(0, p);
}

void GetName(Local<String> property, const PropertyCallbackInfo<Value> &info) {
    Local<Object> self = info.Holder();
    Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
    void *pointer = self->GetAlignedPointerFromInternalField(0);
    const string value = static_cast<Person *>(pointer)->name();
    info.GetReturnValue().Set(
            String::NewFromUtf8(info.GetIsolate(), value.c_str(), NewStringType::kNormal).ToLocalChecked());
}

int main(int argc, char *argv[]) {
    cout << argv << "   " << *argv << "    " << argv[0] << endl;
    V8::InitializeICUDefaultLocation(argv[0]);
    V8::InitializeExternalStartupData(argv[0]);
    unique_ptr<v8::Platform> platform = v8::platform::NewDefaultPlatform();
    V8::InitializePlatform(platform.get());
    V8::Initialize();

    Isolate::CreateParams create_params;
    create_params.array_buffer_allocator = v8::ArrayBuffer::Allocator::NewDefaultAllocator();
    Isolate *isolate = Isolate::New(create_params);
    {
        Isolate::Scope isolate_scope(isolate);
        HandleScope handle_scope(isolate);

        Local<ObjectTemplate> global = ObjectTemplate::New(isolate);

        Local<FunctionTemplate> function_template = FunctionTemplate::New(isolate, NewPerson);
        function_template->SetClassName(String::NewFromUtf8(isolate, "Person").ToLocalChecked());
        function_template->InstanceTemplate()->SetInternalFieldCount(1);
        function_template->InstanceTemplate()->SetAccessor(String::NewFromUtf8(isolate, "name").ToLocalChecked(), GetName, nullptr);

        Local<ObjectTemplate> person_template = ObjectTemplate::New(isolate, function_template);
        person_template->SetInternalFieldCount(1);

        global->Set(String::NewFromUtf8(isolate, "Person", NewStringType::kNormal).ToLocalChecked(), function_template);

        Local<Context> context = Context::New(isolate, NULL, global);
        Context::Scope context_scope(context);

        const char *js = "var user = new Person('Fletch'); user.name;";
        Local<String> source = String::NewFromUtf8(isolate, js, NewStringType::kNormal).ToLocalChecked();

        Local<Script> script = Script::Compile(context, source).ToLocalChecked();
        Local<Value> result = script->Run(context).ToLocalChecked();
        String::Utf8Value utf8{isolate, result};
        printf("Script return value: %s\n", *utf8);
    }

    // Dispose the isolate and tear down V8.
    isolate->Dispose();
    V8::Dispose();
    V8::ShutdownPlatform();
//    delete platform;
    return 0;
}
