#include "SnakeController.h"

#include <chrono>

void SnakeController::set_mode() {
    switch (MODE) {
        case EASY:
            timeToNextMove = 2000;
        case NORMAL:
            timeToNextMove = 1000;
        case HARD:
            timeToNextMove = 500;
        case DEBUG:
            timeToNextMove = 3000;
    }
}

SnakeController::SnakeController(SnakeBoard &board, SnakeModel &model, SnakeView &view) :
BOARD(board), MODEL(model), VIEW(view)
{
    STATE = READY;
}

void SnakeController::next_move() {

}

bool SnakeController::time_to_move() {
   auto timeDifference = std::chrono::system_clock::now() - timer;
}

void SnakeController::change_mode(GameMode mode) {
    MODE = mode;
    set_mode();
}