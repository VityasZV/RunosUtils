cmake_minimum_required(VERSION 3.15)
project(xml_parsing)
include(CheckCXXCompilerFlag)

set(CMAKE_CXX_STANDARD 17)
find_package(Boost 1.72.0 REQUIRED)
find_package(LibNETCONF2 REQUIRED)
find_package(LibYANG REQUIRED)

function(enable_cxx_compiler_flag_if_supported flag)
    string(FIND "${CMAKE_CXX_FLAGS}" "${flag}" flag_already_set)
    if(flag_already_set EQUAL -1)
        check_cxx_compiler_flag("${flag}" flag_supported)
        if(flag_supported)
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flag}" PARENT_SCOPE)
        endif()
        unset(flag_supported CACHE)
    endif()
endfunction()

file(GLOB XML libs/pugixml/*.h libs/pugixml/*.cpp)
file(GLOB MkReq MkRequest/*.h MkRequest/*.cpp)
file(GLOB XMLParser XMLParser/*.h XMLParser/*.cpp)


SET(CMAKE_INCLUDE_PATH ${CMAKE_LIBRARY_PATH} "/usr/local/include")

add_executable(xml_parsing main.cpp ${XML} ${MkReq} ${XMLParser})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/libs)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_INCLUDE_PATH} -lyang)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${Boost_LIBRARIES})
