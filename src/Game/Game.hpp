#pragma once 

#include <Player/Player.hpp>
#include <Ball/Ball.hpp>

class Game {
public:
    Game();

    void update(float dt);

    void draw();

    void start();

    void restart();
private:
    sf::RenderWindow window;
    AssetManager manager;
    Player player;
    Ball ball;
    sf::Clock timer;
};