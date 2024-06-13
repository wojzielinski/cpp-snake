#ifndef SNAKE_SNAKEGAMEMANAGER_H
#define SNAKE_SNAKEGAMEMANAGER_H

#include "SnakeModel.h"
#include "SnakeController.h"
#include "SnakeView.h"

class SnakeGameManager {
    SnakeModel & MODEL;
    SnakeController & CTRL;
    SnakeView & VIEW;
    sf::RenderWindow & WINDOW;

    bool dev_commands;          //top secret flag
    void display_leaderboard();
public:
    SnakeGameManager(SnakeModel & model, SnakeController & ctrl, SnakeView & view, sf::RenderWindow & win);
    void display_game(GameMode mode);
    void display_menu();
    void display_finish();
    void run();
};


#endif //SNAKE_SNAKEGAMEMANAGER_H
