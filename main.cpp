#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>

#include "SnakeModel.h"
#include "SnakeView.h"
#include "SnakeTextView.h"
#include "SnakeController.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake", sf::Style::Close);
    SnakeBoard board(10, 10);
    SnakeModel model(board);
    SnakeController ctrl(board, model);
    SnakeView view(board, model, window);
    SnakeTextView textView(board,model);

    for(int i=0; i<10;++i) board.push_fruit();
    ctrl.change_mode(GameMode::NORMAL);
    ctrl.start();
    while(window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Left)
                    model.turn(LEFT);
                if(event.key.code == sf::Keyboard::Right)
                    model.turn(RIGHT);
            }
        }
        if(ctrl.get_state() != FINISHED)
            ctrl.next_move();
        view.draw();
    }

    return 0;
}