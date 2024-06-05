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

configure_file(assets/sounds/flagSound.wav ${CMAKE_CURRENT_BINARY_DIR}/flagSound.wav COPYONLY)
configure_file(assets/sounds/winSound.wav ${CMAKE_CURRENT_BINARY_DIR}/winSound.wav COPYONLY)
configure_file(assets/sounds/bombSound.wav ${CMAKE_CURRENT_BINARY_DIR}/bombSound.wav COPYONLY)
configure_file(assets/sounds/clickSound.wav ${CMAKE_CURRENT_BINARY_DIR}/clickSound.wav COPYONLY)
configure_file(assets/textures/saper_bg.jpg ${CMAKE_CURRENT_BINARY_DIR}/saper_bg.jpg COPYONLY)
configure_file(assets/fonts/VT323-Regular.ttf ${CMAKE_CURRENT_BINARY_DIR}/VT323-Regular.ttf COPYONLY)
configure_file(assets/textures/mine.png ${CMAKE_CURRENT_BINARY_DIR}/mine.png COPYONLY)
configure_file(assets/textures/flag.png ${CMAKE_CURRENT_BINARY_DIR}/flag.png COPYONLY)
configure_file(assets/textures/icon.png ${CMAKE_CURRENT_BINARY_DIR}/icon.png COPYONLY)

add_executable(snake main.cpp
        SnakeModel.cpp
        SnakeModel.h
        SnakeView.h
        SnakeController.cpp
        SnakeController.h
        SnakeBoard.cpp
        SnakeBoard.h
        SnakeTextView.cpp
        SnakeTextView.h
)

# SFML LINKING
target_link_libraries(snake sfml-graphics sfml-audio)
