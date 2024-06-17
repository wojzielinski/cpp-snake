#include <iostream>
#include "SnakeGameManager.h"

// Constructor - set references to other objects, set dev_commands flag to false
SnakeGameManager::SnakeGameManager(SnakeModel & model, SnakeController & ctrl, SnakeView & view, sf::RenderWindow & win, SnakeLeaderboard & leadrbrd):
MODEL(model),CTRL(ctrl),VIEW(view),WINDOW(win),LEADRBRD(leadrbrd){
    dev_commands = false;
}

// Display current game state, get user input in a loop
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

// Display main manu, get user input
void SnakeGameManager::display_menu() {
    while(WINDOW.isOpen() && CTRL.get_state() == READY){
        sf::Event event;
        while (WINDOW.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                WINDOW.close();
            if (event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Q)
                    WINDOW.close();
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

// Display if GameState = FINISHED
void SnakeGameManager::display_finish() {
    sf::Font font;
    font.loadFromFile("assets/fonts/VT323-Regular.ttf");
    sf::String usrInput;
    sf::Text userName("Enter name: ", font, 50);
    userName.setFillColor(sf::Color(159,217,119));
    userName.setPosition(50,275);
    bool displayLB = false;
    while(WINDOW.isOpen() && CTRL.get_state() == FINISHED){
        sf::Event event;
        while (WINDOW.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                WINDOW.close();
            if (event.type == sf::Event::TextEntered && usrInput.getSize()<24) {
                if(event.text.unicode == 8 && !usrInput.isEmpty()){
                    usrInput.erase(usrInput.getSize()-1, 1);
                }else {
                    usrInput += event.text.unicode;
                }
                userName.setString("Enter name: " + usrInput);
            }
            if (event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Enter && !displayLB){
                    LEADRBRD.add_result(MODEL.get_length()*100, CTRL.get_gamemode(), usrInput);
                    displayLB=true;
                }
                if(event.key.code == sf::Keyboard::R && displayLB){
                    CTRL.set_state(READY);
                }
            }
        }
        WINDOW.clear(sf::Color(44,37,37));
        if(!displayLB)
            WINDOW.draw(userName);
        if(displayLB)
            VIEW.draw_leaderboard();
        WINDOW.display();
    }
}

// Run the game
void SnakeGameManager::run() {
    while (WINDOW.isOpen()){
        if (CTRL.get_state() == READY)
            display_menu();
        if (CTRL.get_state() == FINISHED) {
            display_finish();
        }
    }
}