#include "SnakeView.h"

#include <iostream>

//PRIVATE
//===============

//Generates vector of points matching board size - point will make centre of board fields
void SnakeView::generate_points() {
    //pointsCloud.setPrimitiveType(sf::Points);
    pointsCloud.resize(board.get_width() * board.get_height());
    for(int row=0; row<boardHeight; ++row){
        for(int col=0; col<boardWidth; ++col){
            pointsCloud[row*boardWidth+col] = sf::Vector2f(x_off+col*field_size,y_off+row*field_size);
        }
    }
}

//Creates "restart" button and sets its size, colour and other visuals
void SnakeView::set_restart_button() {
    restartButton.setSize(sf::Vector2f(120,40));
    restartButton.setFillColor(sf::Color(255,191,0));
    restartButton.setOutlineColor(sf::Color::Black);
    restartButton.setOutlineThickness(2);
    restartButton.setOrigin((restartButton.getLocalBounds().left+restartButton.getLocalBounds().width)/2,
                            (restartButton.getLocalBounds().top+restartButton.getLocalBounds().height)/2);
    restartText.setString("RESTART");
    restartText.setFont(font);
    restartText.setCharacterSize(40);
    restartText.setFillColor(sf::Color::Black);
    restartText.setOrigin((restartText.getLocalBounds().left+restartText.getLocalBounds().width)/2,
                          (restartText.getLocalBounds().top+restartText.getLocalBounds().height)/2);
    restartButton.setPosition(400,570);
    restartText.setPosition(restartButton.getPosition().x, restartButton.getPosition().y-10);
}

//Sets textures for flag icon
void SnakeView::set_flag_txt() {
    flagTxt.loadFromFile("flag.png");
    flagSprite.setTexture(flagTxt);
    sf::FloatRect flagRect = flagSprite.getLocalBounds();
    flagSprite.setOrigin( (flagRect.width+flagRect.left)/2,
                          (flagRect.height+flagRect.top)/2);
    flagSprite.setScale(field_size/64.0,field_size/64.0);
}

//Sets textures for mine icon
void SnakeView::set_mine_txt() {
    mineTxt.loadFromFile("mine.png");
    mineSprite.setTexture(mineTxt);
    sf::FloatRect mineRect = mineSprite.getLocalBounds();
    mineSprite.setOrigin( (mineRect.width+mineRect.left)/2,
                          (mineRect.height+mineRect.top)/2);
    mineSprite.setScale(field_size/64.0,field_size/64.0);
}

//Sets visuals for revealed field
void SnakeView::set_field_revealed_txt() {
    fieldRevealed.setRadius(field_size/2.0+3);
    fieldRevealed.setPosition(0,0);
    fieldRevealed.setPointCount(4);
    sf::Color grey(100,100,100,240);
    sf::FloatRect fieldRevRect = fieldRevealed.getLocalBounds();
    fieldRevealed.setFillColor(grey);
    fieldRevealed.setOrigin( (fieldRevRect.width+fieldRevRect.left)/2,
                             (fieldRevRect.height+fieldRevRect.top)/2);
    fieldRevealed.setRotation(45);
}

//Sets visuals for not revealed field
void SnakeView::set_field_txt() {
    field.setRadius(field_size/2.0+5);
    field.setPosition(0,0);
    sf::FloatRect fieldRect = field.getLocalBounds();
    field.setPointCount(4);
    field.setFillColor(sf::Color::Red);
    field.setOrigin( (fieldRect.width+fieldRect.left)/2,
                     (fieldRect.height+fieldRect.top)/2);
    field.setRotation(45);
}

//Sets textures for mine icon
void SnakeView::set_field_mine_txt() {
    fieldWithMine.setRadius(field_size/2.0+5);
    fieldWithMine.setPosition(0,0);
    sf::FloatRect fieldWithMineRect = fieldWithMine.getLocalBounds();
    fieldWithMine.setPointCount(4);
    sf::Color redWithAlpha(255,0,0,200);
    fieldWithMine.setFillColor(redWithAlpha);
    fieldWithMine.setOrigin( (fieldWithMineRect.width+fieldWithMineRect.left)/2,
                             (fieldWithMineRect.height+fieldWithMineRect.top)/2);
    fieldWithMine.setRotation(45);
}

//Sets all assets - background and other textures
void SnakeView::set_textures() {
    //bgImage.loadFromFile("saper_bg.jpg");
    //bgSprite.setTexture(bgImage);

    set_flag_txt();
    set_mine_txt();
    set_field_revealed_txt();
    set_field_txt();
    set_field_mine_txt();
}

//Sets title, that is being displayed above the board
void SnakeView::set_title() {
    font.loadFromFile("VT323-Regular.ttf");
    title.setFont(font);
    title.setString("Minesweeper!");
    title.setCharacterSize(40);
    title.setFillColor(sf::Color::Red);
    sf::FloatRect titleRect = title.getLocalBounds();
    title.setOrigin(
            (titleRect.left + titleRect.width)/2.0f,
            (titleRect.top + titleRect.height)/2.0f
    );
}

//Draws fields depending on it's status (revealed/flagged/mine etc)
void SnakeView::draw_field(int row, int col, sf::RenderWindow & win) {
/*    if(board.isRevealed(row,col)){
        fieldRevealed.setPosition(pointsCloud[row*boardWidth+col].position);
        win.draw(fieldRevealed);
        if(board.getFieldInfo(row,col)=='x'){
            fieldWithMine.setPosition(pointsCloud[(row*boardWidth+col)].position);
            win.draw(fieldWithMine);
            mineSprite.setPosition(pointsCloud[(row*boardWidth+col)].position);
            win.draw(mineSprite);
        } else{
            mineCountText[(board.countMines(row,col))].setPosition(pointsCloud[row*boardWidth+col].position);
            win.draw(mineCountText[board.countMines(row,col)]);
        }
    } else{*/
        field.setPosition(pointsCloud[row*boardWidth+col].position);
        win.draw(field);
        if(board.has_fruit(row*boardWidth+col)){
            flagSprite.setPosition(pointsCloud[row*boardWidth+col].position);
            win.draw(flagSprite);
        }
    /*}*/
}

//Updates board state - renders all fields in given window
void SnakeView::update_board_state( sf::RenderWindow & win ) {
    for(int row=0; row<boardHeight; ++row){
        for(int col=0; col<boardWidth; ++col){
            draw_field(row, col, win);
        }
    }
}


//PUBLIC
//===============

//SFML View constructor - sets board reference and creates view setup
SnakeView::SnakeView(SnakeBoard &boardRef) : board(boardRef),boardWidth(boardRef.get_width()),boardHeight(boardRef.get_height())
{
    field_size=10;
    x_off=90;
    y_off=100;
    generate_points();
    set_title();
    set_textures();
    set_restart_button();
}

//Draws all elements in window, that was passed to function by reference
void SnakeView::draw(sf::RenderWindow &windowRef) {
    windowRef.clear(sf::Color::Black);
    //windowRef.draw(bgSprite);                       //draw background
    update_board_state(windowRef);
    title.setPosition(windowRef.getSize().x/2, 30);   //set title position and string
    /*if(board.getGameState()==FINISHED_LOSS) {
        title.setString("Game Over!");
        title.setOrigin(
                (title.getLocalBounds().left + title.getLocalBounds().width) / 2.0f,
                (title.getLocalBounds().top + title.getLocalBounds().height) / 2.0f
        );
        windowRef.draw(restartButton);
        windowRef.draw(restartText);
    }
    if(board.getGameState()==FINISHED_WIN) {
        title.setString("You won!");
        title.setOrigin(
                (title.getLocalBounds().left + title.getLocalBounds().width) / 2.0f,
                (title.getLocalBounds().top + title.getLocalBounds().height) / 2.0f
        );
        windowRef.draw(restartButton);
        windowRef.draw(restartText);
    }*/
    windowRef.draw(title);
    std::cout << "i was here too" << std::endl;
    /*windowRef.draw(flagsCounter);*/
    windowRef.draw(pointsCloud);          //draws base points (pointsCloud)
    windowRef.display();
}

//Gets point position in window
sf::Vector2i SnakeView::get_point_pos(int row, int col) const {
    sf::Vector2i position(  pointsCloud[row*boardWidth+col].position.x,
                            pointsCloud[row*boardWidth+col].position.y);
    return position;
}

//Gets field size
int SnakeView::get_field_size() const {
    return field_size;
}

//Gets bounds of restart button
sf::FloatRect SnakeView::getRButtonBound() const {
    return restartButton.getGlobalBounds();
}
