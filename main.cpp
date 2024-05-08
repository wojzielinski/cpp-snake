#include <iostream>
#include <random>

#include "SnakeModel.h"
#include "SnakeView.h"
#include "SnakeController.h"

int main() {
    //std::mt19937 gen;
    //std::uniform_int_distribution<int> dist(1,4);

    sf::RenderWindow window(sf::VideoMode(800, 600), "Minesweeper", sf::Style::Close);

    SnakeBoard board(10, 10);
    SnakeModel model(board,DEBUG);
    SnakeView view(board);

    view.draw(window);
    int i=0;
    while(true) i++;
/*
    for (int i = 0; i < 10; ++i) {
        switch (model.rand_direction(gen,dist))
        {
            case UP:
                std::cout << "UP" << std::endl;
                break;
            case DOWN:
                std::cout << "DOWN" << std::endl;
                break;
            case RIGHT:
                std::cout << "RIGHT" << std::endl;
                break;
            case LEFT:
                std::cout << "LEFT" << std::endl;
                break;
        }
    }
    */

    return 0;
}

/* view depends on model
 * controller depends on model and view
 */