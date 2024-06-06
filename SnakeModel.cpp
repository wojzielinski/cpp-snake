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
    std::pair<int,int> newBlock = get_position(0);
    switch(get_direction()) {
        case UP:
            --newBlock.second;
            break;
        case DOWN:
            ++newBlock.second;
            break;
        case LEFT:
            --newBlock.first;
            break;
        case RIGHT:
            ++newBlock.first;
            break;
    }
    body.insert(body.begin(), newBlock);
    if(fruit_eaten()){
        ++length;
        BOARD.remove_fruit(newBlock.first, newBlock.second);
        return;
    }
    body.pop_back();
}

//might want to put this in controller... why does model need to know if it hit the wall? why bother it with another problems...
bool SnakeModel::fruit_eaten() {
    std::pair<int,int> currentPos = get_position(0);
    return BOARD.has_fruit(currentPos.first, currentPos.second);
}

bool SnakeModel::obstacle_hit() {
    std::pair<int,int> currentPos = get_position(0);
    return BOARD.has_obstacle(currentPos.first, currentPos.second);
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

void SnakeModel::turn_left() {
    direction = ((--direction)+4)%4;
}

void SnakeModel::turn_right() {
    direction = ((++direction)+4)%4;
}

//PUBLIC
SnakeModel::SnakeModel( SnakeBoard & boardRef , GameMode mode):
BOARD(boardRef),MODE(mode)
{
    length = 3;
    set_velocity();
    body.push_back(std::pair<int,int>(boardRef.get_width()/2, boardRef.get_height()/2-2));
    body.push_back(std::pair<int,int>(boardRef.get_width()/2, boardRef.get_height()/2-1));
    body.push_back(std::pair<int,int>(boardRef.get_width()/2, boardRef.get_height()/2));
}

Direction SnakeModel::get_direction() const {
    switch (direction) {
        case 0:
            return UP;
        case 1:
            return RIGHT;
        case 2:
            return DOWN;
        case 3:
            return LEFT;
        default:
            return UP;
    }
}

int SnakeModel::get_length() const {
    return length;
}

std::pair<int,int> SnakeModel::get_position(int segment) const {
    return body.at(segment);
}

void SnakeModel::change_direction(Direction dir){
    direction = dir;
}

bool SnakeModel::has_body(int x, int y) {
    if(body.empty()) return false;
    for(auto it=begin(body); it!=end(body); ++it){
        if(it->first == x && it->second==y) return true;
    }
    return false;
}

void SnakeModel::turn(Direction dir) {
    switch (dir) {
        case LEFT:
            turn_left();
            break;
        case RIGHT:
            turn_right();
            break;
        default:
            return;
    }
}

