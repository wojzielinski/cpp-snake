#ifndef SNAKE_SNAKETEXTVIEW_H
#define SNAKE_SNAKETEXTVIEW_H

#include "SnakeBoard.h"
#include "SnakeModel.h"

// NOTE - no longer needed in the project
class SnakeTextView {
    SnakeBoard &board;
    SnakeModel &model;
    const int boardWidth;
    const int boardHeight;

public:
    SnakeTextView(SnakeBoard& boardRef, SnakeModel& modelRef);
    void debug_display();
    char display_field(int x, int y);
};


#endif //SNAKE_SNAKETEXTVIEW_H
