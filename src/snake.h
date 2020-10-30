#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#include "food.h"
#include "ScoreManager.h"

class snake
{
    private:
        std::vector<sf::RectangleShape> snakeobj;
        int size, velx, vely;
        float x, y, lastx, lasty;
        bool up, left, right, down;
        bool moving = false;
        bool exists = true;

    public:
        snake();
        ~snake();

        sf::RectangleShape& getHead() { return snakeobj[0]; }

        void draw(sf::RenderWindow &win);
        void checkMovement(sf::Event &event);
        void checkBounds();
        void checkCollisionWithSelf(ScoreManager& manager, food& fd);
        void performMovement();
        void grow();

        bool checkCollision(sf::RectangleShape& obj);
};
