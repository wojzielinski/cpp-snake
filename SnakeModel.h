#ifndef SNAKE_SNAKEMODEL_H
#define SNAKE_SNAKEMODEL_H

#include <vector>

#include "SnakeBoard.h"

enum GameMode { EASY , NORMAL , HARD , DEBUG };
enum Direction { UP , DOWN , LEFT , RIGHT };

struct Position {
    int row;
    int col;
};

class SnakeModel {
    SnakeBoard & BOARD;
    const GameMode MODE;
    int length;
    float velocity;
    Direction direction;
    std::vector<Position> body;

    void set_velocity();

public:
    SnakeModel(SnakeBoard & boardRef , GameMode mode);
    Direction get_direction() const;
    int get_length() const;
    Position get_position () const;

};


#endif //SNAKE_SNAKEMODEL_H
