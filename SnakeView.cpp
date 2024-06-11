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

void SnakeView::draw_model(sf::RenderWindow & win) {
    int length = model.get_length();

    modelHead.setPosition(get_point_pos(model.get_position(0).first, model.get_position(2).second));
    win.draw(modelHead);
    for(int segment = 1; segment < length; ++segment){
        modelTail.setPosition(get_point_pos(model.get_position(segment).first, model.get_position(segment).second));
        win.draw(modelTail);
    }
}

void SnakeView::draw_fruits(sf::RenderWindow & win) {
    for(std::pair<int,int> & elem : board.get_fruits()){
        fruitShape.setPosition(get_point_pos(elem.first, elem.second));
        win.draw(fruitShape);
    }
}

//PUBLIC
//===============

//SFML View constructor - sets board reference and creates view setup
SnakeView::SnakeView(SnakeBoard &boardRef, SnakeModel & modelRef) :
board(boardRef),model(modelRef),boardWidth(boardRef.get_width()),boardHeight(boardRef.get_height())
{
    field_size=10;
    x_off=100;
    y_off=100;
    generate_points();
    set_shapes();
}

//Draws all elements in window, that was passed to function by reference
void SnakeView::draw(sf::RenderWindow &windowRef) {
    windowRef.clear(sf::Color::Black);
    windowRef.draw(pointsCloud);          //draws base points (pointsCloud)
    draw_fruits(windowRef);
    draw_model(windowRef);
    windowRef.display();
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