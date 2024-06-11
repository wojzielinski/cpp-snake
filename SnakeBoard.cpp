#include <iostream>
#include <random>
#include "SnakeBoard.h"

std::random_device rd;
std::mt19937 gen(rd());

std::pair<int, int> SnakeBoard::rand_position() const {
    std::uniform_int_distribution<int> widthDist(0,width-1);
    std::uniform_int_distribution<int> heightDist(0,height-1);
    std::pair<int,int> pos;
    pos.first = widthDist(gen);
    pos.second = heightDist(gen);
    return pos;
}

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

void SnakeBoard::push_fruit() {
    std::pair<int,int> pos;
    pos = rand_position();
    if(!has_fruit(pos.first,pos.second)){
        fruits.push_back(pos);
        //std::cout << "Pushed fruit on position x: " << pos.first << ", y: " << pos.second << std::endl;
    }
    else push_fruit();
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