#include <iostream>
#include <stdlib.h>
#include "SnakeBoard.h"

std::pair<int, int> SnakeBoard::rand_position() {
    std::pair<int,int> pos;
    pos.first = rand()%width;
    pos.second = rand()%height;
    return pos;
}

//PUBLIC
SnakeBoard::SnakeBoard(int width, int height) : width(width),height(height)
{
    fruits.clear();
    obstacles.clear();
}

int SnakeBoard::get_height() const {
    return height;
}

int SnakeBoard::get_width() const {
    return width;
}

bool SnakeBoard::has_fruit(int x, int y){
   if(fruits.empty()) return false;
   for(auto it=begin(fruits); it!=end(fruits); ++it){
       if(it->first == x && it->second==y) return true;
   }
   return false;
}

bool SnakeBoard::has_obstacle(int x, int y){
    if(obstacles.empty()) return false;
    for(auto it=begin(obstacles); it!=end(obstacles); ++it){
        if(it->first == x && it->second==y) return true;
    }
    return false;
}

void SnakeBoard::push_fruit() {
    std::pair<int,int> pos;
    pos = rand_position();
    if(!has_fruit(pos.first,pos.second) && !has_obstacle(pos.first,pos.second)){
        fruits.push_back(pos);
        std::cout << "Pushed fruit on position x: " << pos.first << ", y: " << pos.second << std::endl;
    }
    else push_fruit();
}

void SnakeBoard::push_obstacle() {
    std::pair<int,int> pos;
    pos = rand_position();
    if(!has_fruit(pos.first,pos.second) && !has_obstacle(pos.first,pos.second)){
        obstacles.push_back(pos);
        std::cout << "Pushed obstacle on position x: " << pos.first << ", y: " << pos.second << std::endl;
    }
    else push_obstacle();
}
