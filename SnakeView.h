#ifndef SNAKE_SNAKEVIEW_H
#define SNAKE_SNAKEVIEW_H

#include "SnakeBoard.h"

#include <SFML/Graphics.hpp>

class SnakeView {
    SnakeBoard & board;
    const int boardWidth;
    const int boardHeight;
    int x_off;
    int y_off;
    int field_size;

    sf::VertexArray pointsCloud;
    sf::Font font;
    sf::Text title;
    sf::Text flagsCounter;
    sf::Text restartText;
    std::vector<sf::Text> mineCountText;
    sf::Texture flagTxt;
    sf::Sprite flagSprite;
    sf::Texture mineTxt;
    sf::Sprite mineSprite;
    sf::CircleShape fieldRevealed;
    sf::CircleShape field;
    sf::CircleShape fieldWithMine;
    sf::Texture bgImage;
    sf::Sprite bgSprite;
    sf::RectangleShape restartButton;

    void generate_points();
    void set_textures();
    void set_title();
    void set_flag_txt();
    void set_mine_txt();
    void set_field_revealed_txt();
    void set_field_txt();
    void set_field_mine_txt();
    void set_restart_button();

    void update_board_state( sf::RenderWindow & win );
    void draw_field( int row, int col, sf::RenderWindow & win );

public:
    explicit SnakeView( SnakeBoard & boardRef);
    void draw( sf::RenderWindow & windowRef );
    sf::Vector2i get_point_pos(int row, int col) const;
    int get_field_size() const;
    sf::FloatRect getRButtonBound() const;
    void update_flags_rem_text();
};

#endif //SNAKE_SNAKEVIEW_H
