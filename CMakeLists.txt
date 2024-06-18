cmake_minimum_required(VERSION 3.26)
project(snake)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror=return-type -Werror=parentheses -Werror=vla -Werror=array-bounds -Wcast-qual -Wmaybe-uninitialized )

configure_file(assets/textures/snake_bg.png ${CMAKE_CURRENT_BINARY_DIR}/assets/textures/snake_bg.png COPYONLY)
configure_file(assets/textures/snake_credits.png ${CMAKE_CURRENT_BINARY_DIR}/assets/textures/snake_credits.png COPYONLY)
configure_file(assets/fonts/VT323-Regular.ttf ${CMAKE_CURRENT_BINARY_DIR}/assets/fonts/VT323-Regular.ttf COPYONLY)
configure_file(assets/readme/icon.png ${CMAKE_CURRENT_BINARY_DIR}/assets/readme/icon.png COPYONLY)

# SFML SETUP FOR WINDOWS
IF (WIN32)
    # Include local sfml cmake config
    set(SFML_DIR "C:/SFML-2.6.1/lib/cmake/SFML")
    # Link sfml statically (Optional)
    set(SFML_STATIC_LIBRARIES TRUE)
ENDIF()

# SFML SETUP
find_package(SFML 2 COMPONENTS graphics REQUIRED)

add_executable(snake main.cpp
        SnakeModel.cpp
        SnakeModel.h
        SnakeView.cpp
        SnakeView.h
        SnakeController.cpp
        SnakeController.h
        SnakeBoard.cpp
        SnakeBoard.h
        SnakeTextView.cpp
        SnakeTextView.h
        SnakeGameManager.cpp
        SnakeGameManager.h
        SnakeLeaderboard.cpp
        SnakeLeaderboard.h
)

# SFML LINKING
target_link_libraries(snake sfml-graphics)
