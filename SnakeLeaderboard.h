#ifndef SNAKE_SNAKELEADERBOARD_H
#define SNAKE_SNAKELEADERBOARD_H

#include "SnakeBoard.h"
#include <vector>
#include <string>
#include <fstream>

struct Result {
    int points;
    std::string user;
    GameMode mode;
    bool operator>(Result & n) const;
    Result();
    Result(int p, std::string u, GameMode m);
    [[nodiscard]] std::string gm_to_str() const;
    [[nodiscard]] std::string result_to_string() const;
};

class SnakeLeaderboard {
    const std::string FILE;
    std::vector<Result> results;

    void read_leaderboard();
    void write_leaderboard();
    [[nodiscard]] GameMode str_to_gamemode(const std::string & str) const;
    void sort_by_points();
    int count_mode_results(GameMode mode);
public:
    explicit SnakeLeaderboard(const std::string & filename);
    std::string get_result(int n, GameMode mode);
    void add_result(int points, GameMode mode, std::string user);
    [[nodiscard]] std::string gamemode_to_str(GameMode mode) const;
};


#endif //SNAKE_SNAKELEADERBOARD_H
