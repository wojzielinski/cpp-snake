#include <iostream>
#include <iomanip>

#include "SnakeTextView.h"

SnakeTextView::SnakeTextView(SnakeBoard &boardRef, SnakeModel &modelRef):
board(boardRef),model(modelRef),boardWidth(boardRef.get_width()),boardHeight(boardRef.get_height())
{
    //might put sth there in a future
}

void SnakeTextView::debug_display() {
    std::cout << std::setw(4) << " ";
    for(int xIndex=0; xIndex<boardWidth;xIndex++){
        std::cout << std::setw(3) << std::right << xIndex;
    }
    std::cout << std::endl;
    for (int y = 0; y < boardHeight; y++) {
        std::cout << std::setw(3) << std::right << y << " ";
        for (int x=0; x < boardWidth; x++) {
            std::cout << std::setw(3) << display_field(x,y);
        }
        std::cout << std::endl;
    }
    std::cout << "Length: " << model.get_length() << std::endl;
}

char SnakeTextView::display_field(int x, int y) {
    if(board.has_fruit(x,y)) return 'F';
    if(board.has_obstacle(x,y)) return 'X';
    if(model.has_body(x,y)) return 'o';
    return '.';
}