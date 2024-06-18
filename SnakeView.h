#ifndef SNAKE_SNAKEVIEW_H
#define SNAKE_SNAKEVIEW_H

#include "SnakeBoard.h"
#include "SnakeModel.h"
#include "SnakeLeaderboard.h"
#include "SnakeController.h"

#include <SFML/Graphics.hpp>

class SnakeView {
    SnakeBoard & board;
    SnakeModel & model;
    SnakeController & ctrl;
    SnakeLeaderboard &ldrbrd;
    sf::RenderWindow & win;

    const int boardWidth;
    const int boardHeight;
    int x_off;
    int y_off;
    int field_size;
    sf::RectangleShape fruitShape;
    sf::RectangleShape obstacleShape;
    sf::RectangleShape modelHead;
    sf::RectangleShape modelTail;
    sf::RectangleShape boundary;
    sf::VertexArray pointsCloud;
    sf::Text resultsLabel;
    sf::Text resultsTitle;
    sf::Text resultsText;
    sf::Text gameInfoPoints;
    sf::Text gameInfoMode;
    sf::Text gameInstructions;

    sf::Color gameBgColor;
    sf::Texture menuBg;
    sf::Sprite menuSprite;
    sf::Texture leaderboardBg;
    sf::Sprite leaderboardSprite;
    sf::Texture credits;
    sf::Sprite creditsSprite;
    sf::Font font;
    void generate_points();
    void set_shapes();
    void draw_model();
    void draw_fruits();
    void draw_obstacles();
    void set_boundary();
    void set_textures(sf::RenderWindow & window);
    void set_labels();
public:
    explicit SnakeView( SnakeBoard & boardRef, SnakeModel & modelRef, SnakeController & ctrlRef, sf::RenderWindow & window, SnakeLeaderboard & leader);
    void draw();
    sf::Vector2f get_point_pos(int row, int col) const;
    void draw_menu();
    void draw_leaderboard();
};

#endif //SNAKE_SNAKEVIEW_H
