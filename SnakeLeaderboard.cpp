#include "SnakeLeaderboard.h"
#include <iostream>

SnakeLeaderboard::SnakeLeaderboard(const std::string & filename) : FILE(filename)
{
    results.clear();
    read_leaderboard();
}

void SnakeLeaderboard::read_leaderboard() {
    std::fstream fs;
    fs.open(FILE,std::fstream::in);
    if(fs.is_open()){
        std::string line;
        Result res;
        std::size_t stFoundAt;
        std::size_t sdFoundAt;
        while(std::getline(fs, line)){
            stFoundAt=line.find(' ');
            res.points = stoi(line.substr(0,stFoundAt),0,10);
            sdFoundAt=line.find(' ', stFoundAt+1);
            res.mode = str_to_gamemode(line.substr(stFoundAt+1, sdFoundAt-stFoundAt-1));
            res.user = line.substr(sdFoundAt+1, line.length());
            results.push_back(res);
        }
        fs.close();
    }
}

GameMode SnakeLeaderboard::str_to_gamemode(const std::string &str) const {
    if(str == "EASY") return EASY;
    if(str == "NORMAL") return NORMAL;
    if(str == "HARD") return HARD;
    return DEBUG;
}

std::string SnakeLeaderboard::gamemode_to_str(GameMode mode) const {
    if(mode == EASY) return "EASY";
    if(mode == NORMAL) return "NORMAL";
    if(mode == HARD) return "HARD";
    if(mode == DEBUG) return "DEBUG";
    return "undefined";
}

std::string SnakeLeaderboard::get_result(int n, GameMode mode) {
    std::string resStr;
    resStr += std::to_string(results[n].points);
    resStr += " ";
    resStr += gamemode_to_str(results[n].mode);
    resStr += " ";
    resStr += results[n].user;
    return resStr;
}