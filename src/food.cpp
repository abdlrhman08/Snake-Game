#include "food.h"

food::food() : exists(true)
{
    srand(time(NULL));
    posX = (rand() % 800);
    int roundedPosX = posX - (posX % 10);
    posY = rand() % 600;
    int roundedPosY = posY - (posY % 10);
    foodrect.setSize(sf::Vector2f(20, 20));
    foodrect.setFillColor(sf::Color::Red);
    foodrect.setPosition(roundedPosX, roundedPosY);

    std::cout << "Created food object at X: " << roundedPosX << " Y: " << roundedPosY << std::endl;
}

food::~food() {}

void food::update() {
    posX = (rand() % 800);
    int roundedPosX = posX - (posX % 10);
    posY = rand() % 600;
    int roundedPosY = posY - (posY % 10);

    foodrect.setPosition(roundedPosX, roundedPosY);
}

void food::draw(sf::RenderWindow& win) {
    if (exists)
        win.draw(foodrect);
}
