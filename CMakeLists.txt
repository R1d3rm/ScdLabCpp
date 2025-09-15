cmake_minimum_required(VERSION 3.10.0)
project(laba2 VERSION 0.1.0 LANGUAGES C CXX)
add_executable(laba2 ip_filter.cpp base.cpp)
set_target_properties(laba2 PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)
if (MSVC)
    target_compile_options(laba2 PRIVATE
        /W4
    )
else()
    target_compile_options(laba2 PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()
install(TARGETS laba2 RUNTIME DESTINATION bin)
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
set(CPACK_PACKAGE_CONTACT example@example.com)
add_subdirectory(gtests)