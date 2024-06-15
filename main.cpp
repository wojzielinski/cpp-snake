#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>

#include "SnakeModel.h"
#include "SnakeTextView.h"
#include "SnakeController.h"
#include "SnakeLeaderboard.h"
#include "SnakeView.h"
#include "SnakeGameManager.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake", sf::Style::Close);
    SnakeBoard board(22, 15);
    SnakeModel model(board);
    SnakeLeaderboard leaderboard("test.txt");
    SnakeController ctrl(board, model, leaderboard);
    SnakeView view(board, model, ctrl, window, leaderboard);
    SnakeTextView textView(board,model);
    SnakeGameManager mngr(model, ctrl, view, window, leaderboard);

    mngr.run();

    return 0;
}