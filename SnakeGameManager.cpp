#include <iostream>
#include "SnakeGameManager.h"
SnakeGameManager::SnakeGameManager(SnakeModel & model, SnakeController & ctrl, SnakeView & view, sf::RenderWindow & win):
MODEL(model),CTRL(ctrl),VIEW(view),WINDOW(win){
    dev_commands = false;
};

void SnakeGameManager::display_game(GameMode mode) {
    CTRL.change_mode(mode);
    CTRL.start();
    while(WINDOW.isOpen() && CTRL.get_state() == RUNNING){
        sf::Event event;
        while (WINDOW.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                WINDOW.close();
            if (event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Left)
                    MODEL.push_direction_change(LEFT);
                if(event.key.code == sf::Keyboard::Right)
                    MODEL.push_direction_change(RIGHT);
            }
        }
        if(CTRL.get_state() != FINISHED)
            CTRL.next_move();
        if(CTRL.get_state() != FINISHED)
            VIEW.draw();
    }
}

void SnakeGameManager::display_menu() {
    while(WINDOW.isOpen() && CTRL.get_state() == READY){
        sf::Event event;
        while (WINDOW.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                WINDOW.close();
            if (event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Num9 && dev_commands)
                    display_game(DEBUG);
                if(event.key.code == sf::Keyboard::Num1)
                    display_game(EASY);
                if(event.key.code == sf::Keyboard::Num2)
                    display_game(NORMAL);
                if(event.key.code == sf::Keyboard::Num3)
                    display_game(HARD);
                dev_commands=false;
                if(event.key.code == sf::Keyboard::Num6)
                    dev_commands = true;
            }
        }
        if(CTRL.get_state() != FINISHED && CTRL.get_state() != RUNNING)
            VIEW.draw_menu();
    }
}

void SnakeGameManager::display_finish() {
    while(WINDOW.isOpen() && CTRL.get_state() == FINISHED){
        sf::Event event;
        while (WINDOW.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                WINDOW.close();
            if (event.type == sf::Event::KeyPressed){
                //if(event.key.code == sf::Keyboard::Num1)
                    //CTRL.restart();
            }
        }
        //if(CTRL.get_state() != FINISHED && CTRL.get_state() != RUNNING)
            VIEW.draw_leaderboard();
    }
}
void SnakeGameManager::run() {
    while (WINDOW.isOpen()){
        if (CTRL.get_state() == READY)
            display_menu();
        if (CTRL.get_state() == FINISHED)
            display_finish();
    }
}