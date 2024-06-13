#ifndef SNAKE_SNAKELEADERBOARD_H
#define SNAKE_SNAKELEADERBOARD_H

#include <vector>
#include <string>
#include <fstream>

#include "SnakeController.h"

struct Result {
    int points;
    std::string user;
    GameMode mode;
};

class SnakeLeaderboard {
    const std::string FILE;
    std::vector<Result> results;

    void read_leaderboard();
    GameMode str_to_gamemode(const std::string & str) const;
    std::string gamemode_to_str(GameMode mode) const;
public:
    SnakeLeaderboard(const std::string & filename);
    //void push_result();
    std::string get_result(int n, GameMode mode);
};


#endif //SNAKE_SNAKELEADERBOARD_H
