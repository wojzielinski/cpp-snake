#ifndef SNAKE_SNAKECONTROLLER_H
#define SNAKE_SNAKECONTROLLER_H

#include "SnakeBoard.h"
#include "SnakeModel.h"
#include "SnakeLeaderboard.h"

#include <SFML/Graphics.hpp>
enum GameState {RUNNING, FINISHED, READY};

class SnakeController {
    SnakeBoard & BOARD;
    SnakeModel & MODEL;
    SnakeLeaderboard & LDRBRD;

    GameMode MODE;
    GameState STATE;
    sf::Clock timer;
    sf::Int32 timeToNextMove;

    void set_mode();
public:
    SnakeController(SnakeBoard & board, SnakeModel & model, SnakeLeaderboard & ldrbrd);
    void next_move();
    void change_mode(GameMode mode);
    bool time_to_move();
    bool outside_board();
    bool hit_tail();
    bool hit_obstacle();
    void start();
    [[nodiscard]] GameState get_state() const;
    [[nodiscard]] GameMode get_gamemode() const;
    void set_state(GameState state);
};


#endif //SNAKE_SNAKECONTROLLER_H
