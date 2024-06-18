#ifndef SNAKE_SNAKEBOARD_H
#define SNAKE_SNAKEBOARD_H

#include <vector>

enum GameMode { EASY , NORMAL , HARD , DEBUG };
class SnakeBoard {
    const int width;
    const int height;
    std::vector<std::pair<int,int>> fruits;
    std::vector<std::pair<int,int>> obstacles;

public:
    SnakeBoard(int width, int height);
    [[nodiscard]] int get_width() const;
    [[nodiscard]] int get_height() const;
    [[nodiscard]] bool has_fruit(int x, int y) const;
    [[nodiscard]] bool has_obstacle(int x, int y) const;
    void push_fruit(std::pair<int,int> pos);
    void push_obstacle(std::pair<int,int> pos);
    void remove_fruit(int x, int y);
    [[nodiscard]] std::vector<std::pair<int,int>> get_fruits() const;
    [[nodiscard]] std::vector<std::pair<int,int>> get_obstacles() const;
    void restart();
};


#endif //SNAKE_SNAKEBOARD_H
