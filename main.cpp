#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>

#include "SnakeModel.h"
#include "SnakeView.h"
#include "SnakeTextView.h"
#include "SnakeController.h"
#include "SnakeGameManager.h"
#include "SnakeLeaderboard.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake", sf::Style::Close);
    SnakeBoard board(20, 15);
    SnakeModel model(board);
    SnakeController ctrl(board, model);
    SnakeView view(board, model, window);
    SnakeTextView textView(board,model);
    SnakeGameManager mngr(model, ctrl, view, window);
    SnakeLeaderboard leaderboard("test.txt");

    for (int n=0; n<3;++n)
        std::cout << leaderboard.get_result(n, DEBUG);

    mngr.run();

    return 0;
}