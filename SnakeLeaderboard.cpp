#include "SnakeLeaderboard.h"
#include <iostream>
#include <algorithm>

// Constructor - clear, read and sort leaderboard from file
SnakeLeaderboard::SnakeLeaderboard(const std::string & filename) : FILE(filename)
{
    results.clear();
    read_leaderboard();
    sort_by_points();
}

// Open file containing leaderboard, read results and push them into "results" vector
void SnakeLeaderboard::read_leaderboard() {
    std::fstream fs;
    fs.open(FILE,std::fstream::in);
    if(fs.is_open()){
        std::string line;
        Result res;
        std::size_t stFoundAt;
        std::size_t sdFoundAt;
        while(std::getline(fs, line)){
            if (line.empty()) break;
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

// Convert string to GameMode
GameMode SnakeLeaderboard::str_to_gamemode(const std::string &str) const {
    if(str == "(E)") return EASY;
    if(str == "(N)") return NORMAL;
    if(str == "(H)") return HARD;
    return DEBUG;
}

// Convert GameMode to string
std::string SnakeLeaderboard::gamemode_to_str(GameMode mode) const {
    if(mode == EASY) return "(E)";
    if(mode == NORMAL) return "(N)";
    if(mode == HARD) return "(H)";
    if(mode == DEBUG) return "DEBUG";
    return "undefined";
}

std::string SnakeLeaderboard::get_result(int n, GameMode mode) {
    if(n >= count_mode_results(mode)) return "-/-";
    std::string resStr;
    int counter = -1;
    int it = -1;
    while(counter != n){
        ++it;
        if (results[it].mode == mode)
            ++counter;
    }
    return results[it].result_to_string();
}

std::string Result::result_to_string() {
    std::string resStr;
    resStr += std::to_string(points);
    resStr += " ";
    resStr += this->gm_to_str();
    resStr += " ";
    resStr += user;
    return resStr;
}

std::string Result::gm_to_str(){
    if(mode == EASY) return "(E)";
    if(mode == NORMAL) return "(N)";
    if(mode == HARD) return "(H)";
    if(mode == DEBUG) return "DEBUG";
    return "undefined";
}

// Sort leaderboard by points earned
void SnakeLeaderboard::sort_by_points() {
    std::sort(results.begin(), results.end(),[](Result & a, Result & b){return a.points>b.points;});
    //sort algorithm docs - https://en.cppreference.com/w/cpp/algorithm/sort
}

// Operator overloading so we can compare Result structures by points
bool Result::operator>(Result & n) const {
    if(this->points > n.points)
        return true;
    return false;
}

Result::Result(){}

Result::Result(int p, std::string u, GameMode m) {
    points = p;
    user = u;
    mode = m;
}

void SnakeLeaderboard::add_result(int points, GameMode mode, std::string user) {
    if (count_mode_results(mode) < 10) {
        results.push_back(Result(points, user, mode));
        sort_by_points();
        write_leaderboard();
        return;
    }
    int lowestResult = results[0].points;       // assuming vector is already sorted
    auto lowestIt = results.begin();
    for (auto it = results.begin(); it != results.end(); ++it) {
        if (it->mode == mode) {
            if (it->points < lowestResult) {
                lowestResult = it->points;
                lowestIt = it;
            }
        }
    }
    if (points > lowestResult){
        *lowestIt = Result(points, user, mode);
        sort_by_points();
        write_leaderboard();
    }
}

int SnakeLeaderboard::count_mode_results(GameMode mode) {
    int counter = 0;
    for( Result & res : results){
        if(res.mode == mode)
            ++counter;
    }
    return counter;
}

void SnakeLeaderboard::write_leaderboard() {
    std::fstream fs;
    fs.open(FILE,std::fstream::out);
    if(fs.is_open()) {
        std::string line;
        for(Result res : results){
            line = res.result_to_string();
            fs << line;
            fs << std::endl;
        }
    }
}