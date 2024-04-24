cmake_minimum_required(VERSION 3.26)
project(snake)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror=return-type -Werror=parentheses -Werror=vla -Werror=array-bounds -Wcast-qual -Wmaybe-uninitialized )

# SFML SETUP FOR WINDOWS
IF (WIN32)
    # Include local sfml cmake config
    set(SFML_DIR "C:/SFML-2.6.1/lib/cmake/SFML")
    # Link sfml statically (Optional)
    set(SFML_STATIC_LIBRARIES TRUE)
ENDIF()

# SFML SETUP
find_package(SFML 2 COMPONENTS graphics audio REQUIRED)

add_executable(snake main.cpp
        SnakeModel.cpp
        SnakeModel.h
        SnakeView.cpp
        SnakeView.h
        SnakeController.cpp
        SnakeController.h
)

# SFML LINKING
target_link_libraries(snake sfml-graphics sfml-audio)
