#ifndef SNAKE_SNAKEMODEL_H
#define SNAKE_SNAKEMODEL_H

#include <random>
#include <vector>

#include "SnakeBoard.h"

enum GameMode { EASY , NORMAL , HARD , DEBUG };
enum Direction { UP , DOWN , LEFT , RIGHT };

class SnakeModel {
    SnakeBoard & BOARD;
    GameMode MODE;
    int length;
    float velocity;
    int direction;
    std::vector<std::pair<int,int>> body;

    void set_velocity();
    bool fruit_eaten();
    bool obstacle_hit();
    void turn_left();
    void turn_right();
    Direction rand_direction() const;
public:
    SnakeModel(SnakeBoard & boardRef , GameMode mode);
    Direction get_direction() const;
    int get_length() const;
    std::pair<int,int> get_position(int segment) const;
    void change_direction(Direction dir);
    void turn(Direction dir);
    void move();
    bool has_body(int x, int y);

};


#endif //SNAKE_SNAKEMODEL_H
