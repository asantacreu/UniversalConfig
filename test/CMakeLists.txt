
cmake_minimum_required(VERSION 3.0)

include(ExternalProject)

project(UConfigTest)

set(CMAKE_CXX_STANDARD 14)

if(MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
endif()


######################################
# GOOGLE TEST DEPENDENCY
######################################

get_filename_component(DEPENDENCIES_ROOT ${PROJECT_BINARY_DIR}/ThirdPartyDependencies ABSOLUTE)

set(GOOGLE_TEST "googleTest")
set(GOOGLE_TEST_PATH "${DEPENDENCIES_ROOT}/${GOOGLE_TEST}")
set(GOOGLE_TEST_INSTALLATION_PATH "${GOOGLE_TEST_PATH}/installation")


set(cmake_googleTest_args -DCMAKE_INSTALL_PREFIX=${GOOGLE_TEST_INSTALLATION_PATH})


ExternalProject_Add(${GOOGLE_TEST}
GIT_REPOSITORY "https://github.com/google/googletest.git"
GIT_TAG "master"
CMAKE_ARGS ${cmake_googleTest_args} ${cmake_global_args}
PREFIX "${GOOGLE_TEST_PATH}"
)


include_directories(${GOOGLE_TEST_INSTALLATION_PATH}/include)
link_directories(${GOOGLE_TEST_INSTALLATION_PATH}/lib)



######################################
# MAIN TARGET
######################################

enable_testing()

add_executable(${PROJECT_NAME}
    main.cpp
    UConfigUnitTest.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

add_dependencies(${PROJECT_NAME} ${GOOGLE_TEST})

if(MSVC)
    target_link_libraries(${PROJECT_NAME} PRIVATE
        debug gtestd optimized gtest
        debug gmockd optimized gmock
            UniversalConfig-static
    )
else()
    target_link_libraries(${PROJECT_NAME} PRIVATE
        gtest
        gmock
            UniversalConfig-static
    )
endif()


add_test(${PROJECT_NAME} ${CMAKE_BINARY_DIR}/../bin/test/UConfigTest)




