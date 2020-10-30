#include <SFML/Graphics.hpp>

#include "snake.h"
#include "ScoreManager.h"
#include "food.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake Game");
    window.setFramerateLimit(10);

    snake player;
    ScoreManager score;
    food fd;


    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            player.checkMovement(event);

        }

        player.performMovement();
        if (player.checkCollision(fd.getObj())) {
            fd.update();
            score.incrementScore();
            player.grow();
        }
        
        player.checkBounds();
        player.checkCollisionWithSelf(score, fd);

        window.clear(sf::Color::Black);

        fd.draw(window);
        player.draw(window);
        score.draw(window);

        window.display();
    }

    return 0;
}
