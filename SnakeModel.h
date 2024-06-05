#ifndef SNAKE_SNAKEMODEL_H
#define SNAKE_SNAKEMODEL_H

#include <random>
#include <vector>

#include "SnakeBoard.h"

enum GameMode { EASY , NORMAL , HARD , DEBUG };
enum Direction { UP , DOWN , LEFT , RIGHT };

class SnakeModel {
    SnakeBoard & BOARD;
    const GameMode MODE;
    int length;
    float velocity;
    Direction direction;
    std::vector<std::pair<int,int>> body;

    void set_velocity();
    void move();
    bool fruit_eaten();

public:
    SnakeModel(SnakeBoard & boardRef , GameMode mode);
    Direction get_direction() const;
    int get_length() const;
    std::pair<int,int> get_position(int segment) const;
    void change_direction(Direction dir);

    //Direction rand_direction(std::mt19937 & gen, std::uniform_int_distribution<int> & dist);
};


#endif //SNAKE_SNAKEMODEL_H
