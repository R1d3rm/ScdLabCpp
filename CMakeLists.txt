# Основной CMakeLists.txt
cmake_minimum_required(VERSION 3.10.0)
set(PATCH_VERSION "2" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(lb2 VERSION ${PROJECT_VESRION})

configure_file(version.h.in version.h)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Создаем библиотеку из общих файлов
add_library(base base.cpp)
target_include_directories(base PUBLIC ${CMAKE_SOURCE_DIR})

# Основной исполняемый файл
add_executable(${PROJECT_NAME} ip_filter.cpp)
target_link_libraries(${PROJECT_NAME} base)

install(TARGETS lb2 RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

add_subdirectory(gtests)