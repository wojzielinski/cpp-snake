#include <iostream>
#include <iomanip>

#include "SnakeTextView.h"

//SnakeTextView::SnakeTextView(SnakeBoard &boardRef, SnakeModel &modelRef):
//board(boardRef),model(modelRef),boardWidth(boardRef.get_width()),boardHeight(boardRef.get_height())
//{
    //might put sth there in a future
//}
SnakeTextView::SnakeTextView(SnakeBoard &boardRef):
        board(boardRef),boardWidth(boardRef.get_width()),boardHeight(boardRef.get_height())
{
    //might put sth there in a future
}

void SnakeTextView::debug_display() {
    std::cout << std::setw(4) << " ";
    for(int a=0; a<boardWidth;a++){
        std::cout << std::setw(3) << std::right << a;
    }
    std::cout << std::endl;
    for (int row = 0; row < boardHeight; row++) {
        std::cout << std::setw(3) << std::right << row << " ";
        for (int col=0; col < boardWidth; col++) {
            std::cout << std::setw(3) << display_field(col,row);
        }
        std::cout << std::endl;
    }
}

char SnakeTextView::display_field(int x, int y) {
    if(board.has_fruit(x,y)) return 'F';
    if(board.has_obstacle(x,y)) return 'X';
    return '.';
}