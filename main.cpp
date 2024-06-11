#include <iostream>
#include <random>

//#include "SnakeModel.h"
//#include "SnakeView.h"
#include "SnakeTextView.h"
#include "SnakeController.h"

int main() {
    //sf::RenderWindow window(sf::VideoMode(800, 600), "Minesweeper", sf::Style::Close);
    SnakeBoard board(10, 10);
    SnakeModel model(board,DEBUG);
    //SnakeView view(board);
    SnakeTextView textView(board,model);

    //textView.debug_display();
    for(int i=0; i<10;++i)
    board.push_fruit();
    board.push_obstacle();
    textView.debug_display();
    model.move();
    textView.debug_display();
    model.move();
    textView.debug_display();
    model.turn(LEFT);
    model.move();
    textView.debug_display();
    model.move();
    textView.debug_display();
    model.turn(LEFT);
    textView.debug_display();
    model.move();
    textView.debug_display();
    model.turn(RIGHT);
    model.move();
    textView.debug_display();
    model.move();
    textView.debug_display();
    model.move();
    textView.debug_display();
    /*
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
        }
        view.draw(window);
    }
     */


    return 0;
}