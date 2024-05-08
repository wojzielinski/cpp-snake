#ifndef SNAKE_SNAKEBOARD_H
#define SNAKE_SNAKEBOARD_H

#include <vector>

struct Field {
    bool hasFruit;
};

class SnakeBoard {
    const int width;
    const int height;
    std::vector<Field> board;

public:
    SnakeBoard(int width, int height);
    int get_width() const;
    int get_height() const;
    bool has_fruit(int pos);
};


#endif //SNAKE_SNAKEBOARD_H
