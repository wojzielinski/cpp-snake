#ifndef SNAKE_SNAKEMODEL_H
#define SNAKE_SNAKEMODEL_H

#include <random>
#include <vector>

#include "SnakeBoard.h"

enum Direction { UP , RIGHT , DOWN , LEFT};

class SnakeModel {
    SnakeBoard & BOARD;
    int length;
    int direction;
    std::vector<std::pair<int,int>> body;
    std::vector<Direction> buffer;          // buffer lets player add moves (direction changes)
                                            // to queue, so there is only one direction change per move
    bool fruit_eaten();
    void turn_left();
    void turn_right();
    [[nodiscard]] int rand_direction() const;
public:
    explicit SnakeModel(SnakeBoard & boardRef);
    [[nodiscard]] Direction get_direction() const;
    [[nodiscard]] int get_length() const;
    [[nodiscard]] std::pair<int,int> get_position(int segment) const;
    void turn(Direction dir);
    [[nodiscard]] bool has_body(int x, int y) const;
    void move();
    [[nodiscard]] std::pair<int,int> rand_position() const;
    [[nodiscard]] std::pair<int,int> rand_obstacle_position() const;
    void push_direction_change(Direction dir);
    Direction pop_direction_change();
    [[nodiscard]] bool buffer_empty() const;
    void restart();
};


#endif //SNAKE_SNAKEMODEL_H
