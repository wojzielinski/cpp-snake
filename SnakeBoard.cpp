#include <iostream>
#include "SnakeBoard.h"

// Constructor - create SnakeBoard and make sure fruits and obstacles are cleared
SnakeBoard::SnakeBoard(int width, int height) : width(width),height(height)
{
    fruits.clear();
    obstacles.clear();
}

// Get height of the board
int SnakeBoard::get_height() const {
    return height;
}

// Get width of the board
int SnakeBoard::get_width() const {
    return width;
}

// Check if position (x,y) has a fruit
bool SnakeBoard::has_fruit(int x, int y) const {
   if(fruits.empty()) return false;
   for(auto it=begin(fruits); it!=end(fruits); ++it){
       if(it->first == x && it->second==y) return true;
   }
   return false;
}

// Check if position (x,y) has an obstacle
bool SnakeBoard::has_obstacle(int x, int y) const {
    if(obstacles.empty()) return false;
    for(auto it=begin(obstacles); it!=end(obstacles); ++it){
        if(it->first == x && it->second==y) return true;
    }
    return false;
}

// Push fruit at position "pos" to fruits vector
void SnakeBoard::push_fruit(std::pair<int,int> pos) {
    if(!has_fruit(pos.first,pos.second)){
        fruits.push_back(pos);
    }
}

// Push obstacle at position "pos" to obstacle vector
void SnakeBoard::push_obstacle(std::pair<int,int> pos) {
    if(!has_fruit(pos.first,pos.second)){
        obstacles.push_back(pos);
    }
}

// Remove fruit at postition (x,y) from fruits vector
void SnakeBoard::remove_fruit(int x, int y) {
    if(fruits.empty()) return;
    for(auto it=begin(fruits); it!=end(fruits); ++it){
        if(it->first == x && it->second==y){
            fruits.erase(it);
            return;
        }
    }
}

// Get all fruits - reference might be better solution(?)
std::vector<std::pair<int, int>> SnakeBoard::get_fruits() const {
    return fruits;
}

// Get all obstacles - reference might be better solution(?)
std::vector<std::pair<int, int>> SnakeBoard::get_obstacles() const {
    return obstacles;
}

// Restart board state
void SnakeBoard::restart() {
    fruits.clear();
    obstacles.clear();
}