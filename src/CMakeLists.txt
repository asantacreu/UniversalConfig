
cmake_minimum_required(VERSION 3.0)

project(UniversalConfig VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)


if(Linux_ARM)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DITV_USA_LINUX")
else()
    if(MSVC)
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd -DUCONFIG_EXPORTS")
        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} /MT -DUCONFIG_EXPORTS")
    endif()
endif()


set(SOURCES
        uConfig.cpp
        )

include_directories(${PROJECT_SOURCE_DIR}/../include/)

add_library(${PROJECT_NAME} SHARED ${SOURCES})
add_library(${PROJECT_NAME}-static STATIC ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})


