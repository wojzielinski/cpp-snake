#ifndef SNAKE_SNAKEBOARD_H
#define SNAKE_SNAKEBOARD_H

#include <vector>

enum GameMode { EASY , NORMAL , HARD , DEBUG };
class SnakeBoard {
    const int width;
    const int height;
    std::vector<std::pair<int,int>> fruits;

public:
    SnakeBoard(int width, int height);
    int get_width() const;
    int get_height() const;
    bool has_fruit(int x, int y) const;
    void push_fruit(std::pair<int,int> pos);
    void remove_fruit(int x, int y);
    std::vector<std::pair<int,int>> get_fruits() const;
    void restart();
};


#endif //SNAKE_SNAKEBOARD_H
