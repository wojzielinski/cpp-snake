#include <SFML/Graphics.hpp>

#include "SnakeModel.h"
#include "SnakeController.h"
#include "SnakeLeaderboard.h"
#include "SnakeView.h"
#include "SnakeGameManager.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake", sf::Style::Close);

    // Set window icon
    sf::Image icon;
    icon.loadFromFile("assets/readme/icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    SnakeBoard board(22, 15);
    SnakeModel model(board);
    SnakeLeaderboard leaderboard("leaderboard.txt");
    SnakeController ctrl(board, model, leaderboard);
    SnakeView view(board, model, ctrl, window, leaderboard);
    SnakeGameManager mngr(model, ctrl, view, window, leaderboard);

    // Play snake :)
    mngr.run();

    // BOARD DIMENSIONS
    // +---------> X
    // |
    // |
    // |
    // \/ Y

    return 0;
}