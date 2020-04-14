CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
project(c++_test)
set(HELLOWORLD helloworld.cpp)
set(SUM sum.cpp)
set(CONSTANT_TEST constant_test.cpp)
set(USING using.cpp)
set(STRING_TEST string_test.cpp)
set(REPEAT repeat.cpp)
set(CHAR char.cpp)
set(VECTOR_TEST vector_test.cpp)
set(FUNCTION_FACT function_fact.cpp)
set(6_10 6_10.cc)
set(ENCAPSULATION encapsulation.cc)
set(STUDENT student.cc)
set(NAMESPACE namespace.cpp)


add_executable(HelloWorld ${HELLOWORLD})
add_executable(Sum ${SUM})
add_executable(Constant_test ${CONSTANT_TEST})
add_executable(Using ${USING})
add_executable(String_test ${STRING_TEST})
add_executable(Repeat ${REPEAT})
add_executable(Char ${CHAR})
add_executable(Vector_test ${VECTOR_TEST})
add_executable(Function_fact ${FUNCTION_FACT})
add_executable(6_10 ${6_10})
add_executable(Encapsulation ${ENCAPSULATION})
add_executable(Student ${STUDENT})
add_executable(Namespace ${NAMESPACE})



#https://www.tutorialspoint.com/What-is-the-difference-between-Cplusplus0x-and-Cplusplus11
#https://stackoverflow.com/questions/9538701/what-is-the-difference-between-c0x-and-c11/9538841
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")

add_subdirectory(class_test)
add_subdirectory(file)
add_subdirectory(v8)