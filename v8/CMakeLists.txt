include_directories(/Volumes/liyao/v8/v8/include)
include_directories(/Volumes/liyao/v8/v8)

link_directories(
        /Volumes/liyao/v8/v8/out.gn/x64.release.sample/obj
)
link_libraries(
        v8_monolith
)

add_executable(01-Objecttemplate_test 01-objecttemplate_test.cc)
add_executable(02-Functionttemplate_test 02-functionttemplate_test.cc)
add_executable(03-Object_test 03-object_test.cc)
add_executable(04-String_test 04-string_test.cc)
add_executable(05-Hello_world 05-hello_world.cc)
add_executable(06-Sample-hello-world 06-sample-hello-world.cc)
add_executable(07-Instance 07-instance.cc)
add_executable(08-Microtasks 08-microtasks.cc)
add_executable(09-Process 09-process.cc)
add_executable(10-Shell 10-shell.cc)

# node 方面的测试
add_executable(01-TestGetOwnNonIndexProperties node/01-testGetOwnNonIndexProperties.cc)