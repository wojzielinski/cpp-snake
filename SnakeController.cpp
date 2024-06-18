#include "SnakeController.h"
#include "SnakeLeaderboard.h"

// Set delay between moves depending on gamemode
void SnakeController::set_mode() {
    switch (MODE) {
        case EASY:
            timeToNextMove = 500;
            break;
        case NORMAL:
            timeToNextMove = 250;
            break;
        case HARD:
            timeToNextMove = 150;
            break;
        case DEBUG:
            timeToNextMove = 1500;
            break;
    }
}

// Constructor - set GameState to READY
SnakeController::SnakeController(SnakeBoard &board, SnakeModel &model, SnakeLeaderboard &ldrbrd) :
BOARD(board), MODEL(model), LDRBRD(ldrbrd)
{
    STATE = READY;
}

// If it's time to move - move snake and check if the snake didn't hit his
// tail/wall/obstacle
void SnakeController::next_move() {
    if(!time_to_move()) return;
    if(STATE == RUNNING){
        if(!MODEL.buffer_empty())
            MODEL.turn(MODEL.pop_direction_change());
        MODEL.move();
        timer.restart();
    }
    if(outside_board() || hit_tail() || hit_obstacle()) {
        STATE = FINISHED;
    }
}

// Check if it's time to move
bool SnakeController::time_to_move() {
    if (timer.getElapsedTime().asMilliseconds() <= (timeToNextMove+50) &&
    timer.getElapsedTime().asMilliseconds() >= (timeToNextMove-50))
        return true;
    return false;
}

// Change gamemode
void SnakeController::change_mode(GameMode mode) {
    MODE = mode;
    set_mode();
}

// Check if model's head is outside the board
bool SnakeController::outside_board() {
    std::pair<int,int> pos;
    pos = MODEL.get_position(0);
    if(pos.first < 0 || pos.first >= BOARD.get_width()) return true;
    if(pos.second < 0 || pos.second >= BOARD.get_height()) return true;
    return false;
}

// Check if model's head hit the tail
bool SnakeController::hit_tail() {
    std::pair<int,int> head_pos;
    head_pos = MODEL.get_position(0);
    for(int segment = 1; segment < MODEL.get_length(); ++segment){
        if(head_pos == MODEL.get_position(segment)) return true;
    }
    return false;
}

// Check if model's head hit an obstacle
bool SnakeController::hit_obstacle() {
    std::pair<int,int> head_pos;
    head_pos = MODEL.get_position(0);
    for(std::pair<int,int> obstacle : BOARD.get_obstacles()){
        if(head_pos == obstacle) return true;
    }
    return false;
}

// Start game - set fruits, obstacles and model
void SnakeController::start() {
    STATE = RUNNING;
    BOARD.restart();
    MODEL.restart();
    BOARD.push_fruit(MODEL.rand_position());
    for(int obstacle = 0; obstacle <= 3*(MODE+1); ++obstacle){
        BOARD.push_obstacle(MODEL.rand_obstacle_position());
    }
    MODEL.move();
    timer.restart();
}

// Get current state of the game
GameState SnakeController::get_state() const {
    return STATE;
}

// Get current mode of the game
GameMode SnakeController::get_gamemode() const {
    return MODE;
}

// Set game state
void SnakeController::set_state(GameState state) {
    STATE = state;
}