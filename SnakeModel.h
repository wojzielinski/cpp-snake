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
public:
    SnakeModel(SnakeBoard & boardRef , GameMode mode);
    Direction get_direction() const;
    int get_length() const;
    std::pair<int,int> get_position(int segment) const;
    void change_direction(Direction dir);
    void turn(Direction dir);
    void move();
    bool has_body(int x, int y);

    //Direction rand_direction(std::mt19937 & gen, std::uniform_int_distribution<int> & dist);
};


#endif //SNAKE_SNAKEMODEL_H
