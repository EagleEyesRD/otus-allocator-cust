cmake_minimum_required(VERSION 3.5)

project(allocator-cust  VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

add_executable(allocator-cust main.cpp)
set_target_properties(allocator-cust PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)


if (MSVC)
    target_compile_options(allocator-cust PRIVATE
        /W4
    )
    
else ()
    target_compile_options(allocator-cust PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    
endif()



install(TARGETS allocator-cust RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT mkubyshkin@internet.ru)

include(CPack)

