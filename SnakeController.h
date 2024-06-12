#ifndef SNAKE_SNAKECONTROLLER_H
#define SNAKE_SNAKECONTROLLER_H

#include "SnakeBoard.h"
#include "SnakeModel.h"
#include "SnakeView.h"

enum GameMode { EASY , NORMAL , HARD , DEBUG };
enum GameState {RUNNING, FINISHED, READY};

class SnakeController {
    const SnakeBoard & BOARD;
    const SnakeModel & MODEL;
    const SnakeView & VIEW;

    GameMode MODE;
    GameState STATE;
    int timer;
    float timeToNextMove;

    void set_mode();
public:
    SnakeController(SnakeBoard & board, SnakeModel & model, SnakeView & view);
    void next_move();
    void change_mode(GameMode mode);
    bool time_to_move();

};


#endif //SNAKE_SNAKECONTROLLER_H
