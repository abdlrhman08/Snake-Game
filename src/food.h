#pragma once

#include <SFML/Graphics.hpp>

#include <stdlib.h>
#include <iostream>
#include <time.h>

class food
{
    private:
        sf::RectangleShape foodrect;

        int posX, posY;

    public:
        bool exists;

    public:
        food();
        ~food();

        sf::RectangleShape& getObj() { return foodrect; }

        void update();
        void draw(sf::RenderWindow &win);
};
