#include "snake.h"

snake::snake(): size(3), x(100), y(100), lastx(x), lasty(y), velx(0), vely(0), up(false), left(false), right(false), down(false) {
    for (int i=0; i<=size; i++) {
        sf::RectangleShape rect(sf::Vector2f(20, 20));
        rect.setPosition(x, y+lasty);
        rect.setFillColor(sf::Color::Green);
        snakeobj.push_back(rect);
        lastx+=10;
        lasty+=30;
    }
}

snake::~snake() {}

void snake::draw(sf::RenderWindow &win) {
    if (exists) {
        for (int i = 0; i < snakeobj.size(); i++) {
            win.draw(snakeobj[i]);
        }
    }
}

void snake::checkBounds() {
    sf::Vector2f pos = snakeobj[0].getPosition();

    if (pos.x > 800)
        snakeobj[0].setPosition(0, pos.y);
    else if (pos.x < 0)
        snakeobj[0].setPosition(800, pos.y);
    else if (pos.y < 0)
        snakeobj[0].setPosition(pos.x, 600);
    else if (pos.y > 600)
        snakeobj[0].setPosition(pos.x, 0);
}

void snake::grow() {
    sf::RectangleShape rect(sf::Vector2f(20, 20));
    rect.setPosition(x, y+lasty);
    rect.setFillColor(sf::Color::Green);
    snakeobj.push_back(rect);
    lasty+=30;

    std::cout << " Current snake size: " << snakeobj.size() << std::endl;
}

void snake::checkMovement(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed) {
        moving = true;

        switch(event.key.code) {
        case (sf::Keyboard::Up):
            if (!down) {
                up = true;
                left = false;
                right = false;

            }
            break;
        case (sf::Keyboard::Down):
            if (!up) {
                down = true;
                left = false;
                right = false;
            }
            break;
        case (sf::Keyboard::Left):
            if (!right) {
                left = true;
                up = false;
                down = false;
            }
            break;
        case (sf::Keyboard::Right):
            if (!left) {
                right= true;
                up = false;
                down = false;
            }
            break;

        }
    }
}

bool snake::checkCollision(sf::RectangleShape& obj) {
    if (snakeobj[0].getGlobalBounds().intersects(obj.getGlobalBounds()))
        return true;
    else return false;

}

void snake::performMovement() {
    sf::Vector2f pos = snakeobj[0].getPosition();

    if (up) {
        vely = -30;
        velx = 0;
    } else if (down) {
        vely = 30;
        velx  = 0;
    }  else if (right) {
        vely = 0;
        velx  = 30;
    }  else if (left) {
        vely = 0;
        velx  = -30;
    }      

    sf::RectangleShape rect(sf::Vector2f(20, 20));
    rect.setPosition(pos.x+velx, pos.y+vely);
    rect.setFillColor(sf::Color::Green);

    if (moving) {
        snakeobj.insert(snakeobj.begin() + 0, rect);
        snakeobj.pop_back();
    }
}

void snake::checkCollisionWithSelf(ScoreManager& manager, food& fd) {
    for (int i = 1; i < snakeobj.size(); i++) {
        if (checkCollision(snakeobj[i])) {
            exists = false;
            fd.exists = false;
            manager.reset();
            manager.gameOver();
            velx = 0;
            vely = 0;
        }
    }
}
