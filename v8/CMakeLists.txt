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