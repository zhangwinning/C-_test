#include <iostream>
#include "include/v8.h"
#include "include/v8-internal.h"
#include "include/libplatform/libplatform.h"

//using namespace std;
using namespace v8;
//using namespace v8-internal

//namespace i = v8::internal;

int main(int argc, char *argv[]) {
//    cout << argv << "   " << *argv << "    " << argv[0] << endl;
//    V8::InitializeICUDefaultLocation(argv[0]);
//    V8::InitializeExternalStartupData(argv[0]);
//    unique_ptr<v8::Platform> platform = v8::platform::NewDefaultPlatform();
//    V8::InitializePlatform(platform.get());
//    V8::Initialize();
//
//    Isolate::CreateParams create_params;
//    create_params.array_buffer_allocator = ArrayBuffer::Allocator::NewDefaultAllocator();
//    Isolate *isolate_ = Isolate::New(create_params);
//    const HandleScope handle_scope(isolate_);
//    Handle<Context> context = Context::New(isolate_);
//    Context::Scope context_scope(context);

    v8::internal::Heap
//    cout << obj.ptr() <<endl;
}