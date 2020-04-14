include_directories(/Users/videojj/v8/v8/include)
include_directories(/Users/videojj/v8/v8)

link_directories(
        /Users/videojj/v8/v8/out.gn/x64.release.sample/obj
)
link_libraries(
        v8_monolith
)

add_executable(test test.cc)