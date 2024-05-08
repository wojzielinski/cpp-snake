#include <iostream>
#include <random>

#include "SnakeModel.h"
#include "SnakeBoard.h"
//PRIVATE
void SnakeModel::set_velocity() {
    switch (MODE) {
        case EASY:
            velocity = 0.5;
            break;
        case NORMAL:
            velocity = 1;
            break;
        case HARD:
            velocity = 1.5;
            break;
        case DEBUG:
            velocity = 0.1;
            break;
    }
}

void SnakeModel::move() {
    Position newBlock = get_position(0);
    switch(get_direction()) {
        case UP:
            --newBlock.row;
            break;
        case DOWN:
            ++newBlock.row;
            break;
        case LEFT:
            --newBlock.col;
            break;
        case RIGHT:
            ++newBlock.col;
            break;
    }
    body.insert(body.begin(), newBlock);
    if(!fruit_eaten())
        body.pop_back();
}

bool SnakeModel::fruit_eaten() {
    Position currentPos = get_position(0);
    return BOARD.has_fruit(currentPos.row * BOARD.get_width() + currentPos.col);
}
/*
Direction SnakeModel::rand_direction(std::mt19937 & generator, std::uniform_int_distribution<int> & dist) {
    Direction dir;
        int randomNumber = dist(generator);
        std::cout << randomNumber << std::endl;
    switch (randomNumber) {
        case 1:
            dir = Direction::UP;
            break;
        case 2:
            dir = Direction::RIGHT;
            break;
        case 3:
            dir = Direction::DOWN;
            break;
        case 4:
            dir = Direction::LEFT;
            break;
    }
    return dir;
}
 */

//PUBLIC
SnakeModel::SnakeModel( SnakeBoard & boardRef , GameMode mode) : BOARD(boardRef),MODE(mode)
{
    length = 3;
    set_velocity();

}

Direction SnakeModel::get_direction() const {
    return direction;
}

int SnakeModel::get_length() const {
    return length;
}

Position SnakeModel::get_position(int segment) const {
    return body.at(segment);
}

void SnakeModel::change_direction(Direction dir) {
   direction = dir;
}