#include <iostream>

#include "SnakeBoard.h"

//PUBLIC
SnakeBoard::SnakeBoard(int width, int height) : width(width),height(height)
{
    std::cout << "i was here" << std::endl;
    board.resize(width*height, Field {false});
}

int SnakeBoard::get_height() const {
    return height;
}

int SnakeBoard::get_width() const {
    return width;
}

bool SnakeBoard::has_fruit(int pos){
    return board.at(pos).hasFruit;
}