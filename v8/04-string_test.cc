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

    Isolate::Scope isolate_scope(isolate_);
    const char *prop_name = "str_name";
    Local<String> str = String::NewFromUtf8(isolate_,
                                            prop_name,
                                            NewStringType::kNormal,
                                            1).ToLocalChecked();
    // String::Utf8Value 可以把一个对象 str, 解码成 UTF-8 的字符数组，如果想
    // 打印的话是十分有用的。
    String::Utf8Value value(isolate_, str);
    cout << *value << endl;
    cout << str->Length() << endl;  // 打印字符串的长度
    cout << str->Utf8Length(isolate_) << endl;  //
}