#ifndef SNAKE_SNAKEBOARD_H
#define SNAKE_SNAKEBOARD_H

#include <vector>

class SnakeBoard {
    const int width;
    const int height;
    std::vector<std::pair<int,int>> fruits;
    std::vector<std::pair<int,int>> obstacles;

    std::pair<int,int> rand_position();
public:
    SnakeBoard(int width, int height);
    int get_width() const;
    int get_height() const;
    bool has_fruit(int x, int y);
    bool has_obstacle(int x, int y);
    void push_fruit();
    void push_obstacle();
};


#endif //SNAKE_SNAKEBOARD_H
