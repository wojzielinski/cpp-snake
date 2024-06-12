#include "SnakeView.h"

//PRIVATE
//===============

//Generates vector of points matching board size - point will make centre of board fields
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

void SnakeView::set_shapes() {
    fruitShape.setSize(sf::Vector2f(field_size, field_size));
    fruitShape.setFillColor(sf::Color::Red);
    modelHead.setSize(sf::Vector2f(field_size, field_size));
    modelHead.setFillColor(sf::Color::Blue);
    modelTail.setSize(sf::Vector2f(field_size, field_size));
    modelTail.setFillColor(sf::Color::White);
}

void SnakeView::draw_model() {
    int length = model.get_length();

    modelHead.setPosition(get_point_pos(model.get_position(0).second, model.get_position(0).first));
    win.draw(modelHead);
    for(int segment = 1; segment < length; ++segment){
        modelTail.setPosition(get_point_pos(model.get_position(segment).second, model.get_position(segment).first));
        win.draw(modelTail);
    }
}

void SnakeView::draw_fruits() {
    for(std::pair<int,int> & elem : board.get_fruits()){
        fruitShape.setPosition(get_point_pos(elem.second, elem.first));
        win.draw(fruitShape);
    }
}

void SnakeView::set_boundary() {
    boundary.setPosition(x_off, y_off);
    boundary.setSize(sf::Vector2f(boardWidth*field_size,boardHeight*field_size));
    boundary.setFillColor(sf::Color::Transparent);
    boundary.setOutlineColor(sf::Color::Green);
    boundary.setOutlineThickness(5);
}

//PUBLIC
//===============

//SFML View constructor - sets board reference and creates view setup
SnakeView::SnakeView(SnakeBoard &boardRef, SnakeModel & modelRef, sf::RenderWindow & window) :
board(boardRef),model(modelRef),win(window),boardWidth(boardRef.get_width()),boardHeight(boardRef.get_height())
{
    field_size=30;
    x_off=60;
    y_off=60;
    generate_points();
    set_shapes();
    set_boundary();
}

//Draws all elements in window, that was passed to function by reference
void SnakeView::draw() {
    win.clear(sf::Color::Black);
    //win.draw(pointsCloud);          //draws base points (pointsCloud)
    draw_fruits();
    draw_model();
    win.draw(boundary);
    win.display();
}

//Gets point position in window
sf::Vector2f SnakeView::get_point_pos(int row, int col) const {
    sf::Vector2f position(  pointsCloud[row*boardWidth+col].position.x,
                            pointsCloud[row*boardWidth+col].position.y);
    return position;
}

//Gets field size
int SnakeView::get_field_size() const {
    return field_size;
}