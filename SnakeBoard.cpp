#include <iostream>
#include <random>
#include "SnakeBoard.h"


//PUBLIC
SnakeBoard::SnakeBoard(int width, int height) : width(width),height(height)
{
    fruits.clear();
}

int SnakeBoard::get_height() const {
    return height;
}

int SnakeBoard::get_width() const {
    return width;
}

bool SnakeBoard::has_fruit(int x, int y) const {
   if(fruits.empty()) return false;
   for(auto it=begin(fruits); it!=end(fruits); ++it){
       if(it->first == x && it->second==y) return true;
   }
   return false;
}

bool SnakeBoard::has_obstacle(int x, int y) const {
    if(obstacles.empty()) return false;
    for(auto it=begin(obstacles); it!=end(obstacles); ++it){
        if(it->first == x && it->second==y) return true;
    }
    return false;
}

void SnakeBoard::push_fruit(std::pair<int,int> pos) {
    if(!has_fruit(pos.first,pos.second)){
        fruits.push_back(pos);
    }
}

void SnakeBoard::push_obstacle(std::pair<int,int> pos) {
    if(!has_fruit(pos.first,pos.second)){
        obstacles.push_back(pos);
    }
}

void SnakeBoard::remove_fruit(int x, int y) {
    if(fruits.empty()) return;
    for(auto it=begin(fruits); it!=end(fruits); ++it){
        if(it->first == x && it->second==y){
            fruits.erase(it);
            return;
        }
    }
}

std::vector<std::pair<int, int>> SnakeBoard::get_fruits() const {
    return fruits;
}

std::vector<std::pair<int, int>> SnakeBoard::get_obstacles() const {
    return obstacles;
}

void SnakeBoard::restart() {
    fruits.clear();
    obstacles.clear();
}