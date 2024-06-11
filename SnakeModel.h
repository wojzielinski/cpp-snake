#ifndef SNAKE_SNAKEMODEL_H
#define SNAKE_SNAKEMODEL_H

#include <random>
#include <vector>

#include "SnakeBoard.h"

enum Direction { UP , DOWN , LEFT , RIGHT };

class SnakeModel {
    SnakeBoard & BOARD;
    int length;
    int direction;
    std::vector<std::pair<int,int>> body;

    bool fruit_eaten();
    void turn_left();
    void turn_right();
    int rand_direction() const;
public:
    SnakeModel(SnakeBoard & boardRef);
    Direction get_direction() const;
    int get_length() const;
    std::pair<int,int> get_position(int segment) const;
    int direction_to_int(Direction dir);
    void turn(Direction dir);
    bool has_body(int x, int y) const;
    void move();
};


#endif //SNAKE_SNAKEMODEL_H
