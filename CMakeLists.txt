cmake_minimum_required(VERSION 3.11)

project(get_ip CXX)
set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo_multi.cmake)
conan_basic_setup(TARGETS)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(get_ip main.cpp)

if (CMAKE_SYSTEM_NAME MATCHES "^MINGW")
  set(SYSTEM_LIBS -lstdc++)
else()
  set(SYSTEM_LIBS)
endif()

target_include_directories(get_ip PRIVATE CONAN_PKG::boost)
target_link_libraries(get_ip PRIVATE Threads::Threads CONAN_PKG::boost)
target_link_libraries(get_ip ${SYSTEM_LIBS})
