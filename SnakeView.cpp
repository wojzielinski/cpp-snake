#include "SnakeView.h"

//Generates vector of points matching board size - point will act as a top left corner of field
void SnakeView::generate_points() {
    pointsCloud.setPrimitiveType(sf::Points);
    pointsCloud.resize(board.get_width() * board.get_height());
    for(int row=0; row<boardHeight; ++row){
        for(int col=0; col<boardWidth; ++col){
            pointsCloud[row*boardWidth+col] = sf::Vector2f(x_off+col*field_size,y_off+row*field_size);
            pointsCloud[row*boardWidth+col].color = sf::Color::Cyan;
        }
    }
}

// Set fruit, obstacle, model shapes
void SnakeView::set_shapes() {
    fruitShape.setSize(sf::Vector2f(field_size, field_size));
    fruitShape.setFillColor(sf::Color::Red);
    obstacleShape.setSize(sf::Vector2f(field_size, field_size));
    obstacleShape.setFillColor(sf::Color::White);
    modelHead.setSize(sf::Vector2f(field_size, field_size));
    modelHead.setFillColor(sf::Color(34,177,76));
    modelTail.setSize(sf::Vector2f(field_size, field_size));
    modelTail.setFillColor(sf::Color(181,230,29));
}

// Draw model
void SnakeView::draw_model() {
    int length = model.get_length();

    modelHead.setPosition(get_point_pos(model.get_position(0).second, model.get_position(0).first));
    win.draw(modelHead);
    for(int segment = 1; segment < length; ++segment){
        modelTail.setPosition(get_point_pos(model.get_position(segment).second, model.get_position(segment).first));
        if(segment%2) modelTail.setFillColor(sf::Color(96,122,15));
        win.draw(modelTail);
        modelTail.setFillColor(sf::Color(181,230,29));
    }
}

// Draw fruits
void SnakeView::draw_fruits() {
    for(std::pair<int,int> & elem : board.get_fruits()){
        fruitShape.setPosition(get_point_pos(elem.second, elem.first));
        win.draw(fruitShape);
    }
}

// Draw obstacles
void SnakeView::draw_obstacles() {
    for(std::pair<int,int> & elem : board.get_obstacles()){
        obstacleShape.setPosition(get_point_pos(elem.second, elem.first));
        win.draw(obstacleShape);
    }
}

// Set boundary
void SnakeView::set_boundary() {
    boundary.setPosition(x_off, y_off);
    boundary.setSize(sf::Vector2f(boardWidth*field_size,boardHeight*field_size));
    boundary.setFillColor(sf::Color::Transparent);
    boundary.setOutlineColor(sf::Color::Green);
    boundary.setOutlineThickness(5);
}

// SFML View constructor - sets board reference and creates view setup
SnakeView::SnakeView(SnakeBoard &boardRef, SnakeModel & modelRef, SnakeController & ctrlRef, sf::RenderWindow & window, SnakeLeaderboard & leader) :
board(boardRef),model(modelRef),ctrl(ctrlRef),ldrbrd(leader),win(window),boardWidth(boardRef.get_width()),boardHeight(boardRef.get_height())
{
    field_size=30;
    x_off=60;
    y_off=60;
    gameBgColor = sf::Color(44,37,37);
    generate_points();
    set_shapes();
    set_boundary();
    font.loadFromFile("assets/fonts/VT323-Regular.ttf");
    set_labels();
    set_textures(window);
}

// Set labels for game and leaderboard view
void SnakeView::set_labels() {
    resultsTitle.setFont(font);
    resultsTitle.setFillColor(sf::Color(159,217,119));
    resultsTitle.setCharacterSize(70);
    resultsTitle.setString("LEADERBOARD");
    resultsTitle.setPosition(250,10);
    resultsLabel.setFillColor(sf::Color::White);
    resultsLabel.setFont(font);
    resultsLabel.setCharacterSize(35);
    resultsText.setFont(font);
    resultsText.setFillColor(sf::Color(159,217,119));
    resultsText.setCharacterSize(40);
    resultsText.setString("Press R to restart");
    resultsText.setPosition(260,520);

    gameInstructions.setFont(font);
    gameInstructions.setFillColor(sf::Color(159,217,119));
    gameInstructions.setCharacterSize(40);
    gameInstructions.setString("Press left/right arrow to move\nwhite=obstacle, red=fruit");
    gameInstructions.setPosition(55,510);

    gameInfoPoints.setFont(font);
    gameInfoPoints.setFillColor(sf::Color(159,217,119));
    gameInfoPoints.setCharacterSize(30);
    gameInfoPoints.setPosition(50,10);

    gameInfoMode.setFont(font);
    gameInfoMode.setFillColor(sf::Color(159,217,119));
    gameInfoMode.setCharacterSize(30);
    gameInfoMode.setPosition(680,10);
}

// Set textures (menubg, credits :)
void SnakeView::set_textures(sf::RenderWindow & window) {
    menuBg.loadFromFile("assets/textures/snake_bg.png");
    menuSprite.setTexture(menuBg);
    menuSprite.setPosition(0,0);
    credits.loadFromFile("assets/textures/snake_credits.png");
    creditsSprite.setTexture(credits);
    creditsSprite.setPosition(0,window.getSize().y-credits.getSize().y);
}

// Draws all elements in window, that was passed to function by reference
void SnakeView::draw() {
    win.clear(gameBgColor);
    //win.draw(pointsCloud);          //draws base points (pointsCloud)
    draw_fruits();
    draw_obstacles();
    draw_model();
    gameInfoPoints.setString("Score: " + std::to_string(model.get_length()*100));
    gameInfoMode.setString(ldrbrd.gamemode_to_str(ctrl.get_gamemode()));
    win.draw(gameInfoPoints);
    win.draw(gameInfoMode);
    win.draw(gameInstructions);
    win.draw(boundary);
    win.display();
}

// Gets point position in window
sf::Vector2f SnakeView::get_point_pos(int row, int col) const {
    sf::Vector2f position(  pointsCloud[row*boardWidth+col].position.x,
                            pointsCloud[row*boardWidth+col].position.y);
    return position;
}

// Draw main menu
void SnakeView::draw_menu() {
    win.clear(sf::Color::Black);
    win.draw(menuSprite);
    win.draw(creditsSprite);
    win.display();
}

// Draw leaderboard
void SnakeView::draw_leaderboard() {
    win.clear(gameBgColor);
    GameMode mode = ctrl.get_gamemode();
    resultsLabel.setPosition(100,90);
    for(int it = 0; it < 10; ++it){
        resultsLabel.setString(std::to_string(it+1) + ". " + ldrbrd.get_result(it,mode));
        win.draw(resultsLabel);
        resultsLabel.setPosition(resultsLabel.getPosition().x, resultsLabel.getPosition().y + 42);
    }
    win.draw(resultsTitle);
    win.draw(resultsText);
}