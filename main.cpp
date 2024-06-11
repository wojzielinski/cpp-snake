#include <iostream>
#include <random>

#include "SnakeModel.h"
#include "SnakeView.h"
#include "SnakeTextView.h"
#include "SnakeController.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake", sf::Style::Close);
    SnakeBoard board(10, 10);
    SnakeModel model(board);
    SnakeView view(board, model);
    SnakeTextView textView(board,model);

    for(int i=0; i<10;++i) board.push_fruit();
    textView.debug_display();
    model.move();
    textView.debug_display();
    model.turn(LEFT);
    model.move();
    textView.debug_display();
    model.turn(LEFT);
    model.move();
    textView.debug_display();
    model.turn(RIGHT);
    model.move();
    textView.debug_display();

    while(window.isOpen()){
        view.draw(window);
    }

    return 0;
}