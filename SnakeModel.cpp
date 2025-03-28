#include <random>

#include "SnakeModel.h"
#include "SnakeBoard.h"

// Random numbers generator
std::random_device rd;
std::mt19937 gen(rd());

// Generate random position for fruit placement
std::pair<int, int> SnakeModel::rand_position() const {
    std::uniform_int_distribution<int> widthDist(0, BOARD.get_width() - 1);
    std::uniform_int_distribution<int> heightDist(0, BOARD.get_height() - 1);
    std::pair<int, int> pos;
    do {
        pos.first = widthDist(gen);
        pos.second = heightDist(gen);
    } while (has_body(pos.first, pos.second) || BOARD.has_fruit(pos.first, pos.second)
            || BOARD.has_obstacle(pos.first, pos.second));
    return pos;
}

// Generate random position for obstacle placement
std::pair<int, int> SnakeModel::rand_obstacle_position() const {
    std::uniform_int_distribution<int> widthDist(1, BOARD.get_width() - 2);
    std::uniform_int_distribution<int> heightDist(1, BOARD.get_height() - 2);
    std::pair<int, int> pos;
    do {
        pos.first = widthDist(gen);
        pos.second = heightDist(gen);
    } while ((pos.first <= body[0].first+3 && pos.first >= body[0].first-3 &&
            pos.second <= body[0].second+3 && pos.second >= body[0].second-3)
            || BOARD.has_obstacle(pos.first,pos.second)
            || BOARD.has_fruit(pos.first,pos.second));
    return pos;
}

// Move model depending on current model's direction
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
        BOARD.push_fruit(rand_position());
        return;
    }
    if(length == 1){
        ++length;
        return;
    }
    body.pop_back();
}

//might want to put this in controller... why does model need to know if it hit the wall? why bother it with another problems...
bool SnakeModel::fruit_eaten() {
    std::pair<int,int> currentPos = get_position(0);
    return BOARD.has_fruit(currentPos.first, currentPos.second);
}

//Returns random direction - used only once in constructor
int SnakeModel::rand_direction() const {
    std::uniform_int_distribution<int> dist(0,3);
    int randomNumber = dist(gen);
    return randomNumber;
}

// Make snake go left
void SnakeModel::turn_left() {
    int newDirection = direction-1;
    direction = (newDirection+4)%4;
}

// Make snake go right
void SnakeModel::turn_right() {
    int newDirection = direction+1;
    direction = (newDirection+4)%4;
}

// Constructor
SnakeModel::SnakeModel( SnakeBoard & boardRef):
BOARD(boardRef)
{
    length = 1;
    direction = rand_direction();     //set random direction at the start
    body.push_back(std::pair<int,int>(boardRef.get_width()/2, boardRef.get_height()/2));    //push snake head
}

// Get current direction
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
            return UP;      //just to make compiler happy ^_^
    }
}

// Get model's length
int SnakeModel::get_length() const {
    return length;
}

//Get position of chosen segment - get_position(0) returns position of head
std::pair<int,int> SnakeModel::get_position(int segment) const {
    return body.at(segment);
}

// These few lines of code call Sherlock Holmes, who inspects given point with his magnifying glass
// and returns appropriate report on that matter.
bool SnakeModel::has_body(int x, int y) const {
    if(body.empty()) return false;
    for(auto it=begin(body); it!=end(body); ++it){
        if(it->first == x && it->second==y) return true;
    }
    return false;
}

// Let the snake turn either left or right
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

// Push direction changes to buffer
void SnakeModel::push_direction_change(Direction dir) {
    if(dir == Direction::LEFT || dir == Direction::RIGHT)
        buffer.push_back(dir);
}

// Get first direction change from buffer
Direction SnakeModel::pop_direction_change() {
    Direction dir=buffer.front();
    buffer.erase(buffer.begin());
    return dir;
}

// Check if buffer with direction changes is empty
bool SnakeModel::buffer_empty() const {
    if(buffer.size() == 0) return true;
    return false;
}

// Restart model
void SnakeModel::restart() {
    body.clear();
    length = 1;
    direction = rand_direction();     //set random direction at the start
    body.push_back(std::pair<int,int>(BOARD.get_width()/2, BOARD.get_height()/2));    //push snake head
}