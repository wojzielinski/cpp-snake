#ifndef SNAKE_SNAKECONTROLLER_H
#define SNAKE_SNAKECONTROLLER_H

#include "SnakeBoard.h"
#include "SnakeModel.h"
#include "SnakeView.h"

#include <SFML/Graphics.hpp>
enum GameMode { EASY , NORMAL , HARD , DEBUG };
enum GameState {RUNNING, FINISHED, READY};

class SnakeController {
    SnakeBoard & BOARD;
    SnakeModel & MODEL;

    GameMode MODE;
    GameState STATE;
    sf::Clock timer;
    sf::Int32 timeToNextMove;

    void set_mode();
    std::pair<int,int> rand_position() const;
public:
    SnakeController(SnakeBoard & board, SnakeModel & model);
    void next_move();
    void change_mode(GameMode mode);
    bool time_to_move();
    bool outside_board();
    bool hit_tail();
    void start();
    GameState get_state();
};


#endif //SNAKE_SNAKECONTROLLER_H
