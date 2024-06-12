#ifndef SNAKE_SNAKEVIEW_H
#define SNAKE_SNAKEVIEW_H

#include "SnakeBoard.h"
#include "SnakeModel.h"

#include <SFML/Graphics.hpp>

class SnakeView {
    SnakeBoard & board;
    SnakeModel & model;
    sf::RenderWindow & win;

    const int boardWidth;
    const int boardHeight;
    int x_off;
    int y_off;
    int field_size;
    sf::RectangleShape fruitShape;
    sf::RectangleShape modelHead;
    sf::RectangleShape modelTail;

    sf::VertexArray pointsCloud;

    void generate_points();
    void set_shapes();
    void draw_model();
    void draw_fruits();
public:
    explicit SnakeView( SnakeBoard & boardRef, SnakeModel & modelRef, sf::RenderWindow & window);
    void draw();
    sf::Vector2f get_point_pos(int row, int col) const;
    int get_field_size() const;
};

#endif //SNAKE_SNAKEVIEW_H
