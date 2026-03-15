#pragma once

#include <SFML/Graphics.hpp>
#include <AssetManager/AssetManager.hpp>

class Ball {
public:
    Ball(AssetManager& manager);

    void update(float dt);

    void draw(sf::RenderWindow& window);

    sf::FloatRect getGlobalBound() const;

    sf::Vector2f getVelocity() const;

    sf::Vector2f setVelocity(sf::Vector2f newVelocity);
private:
    AssetManager& assets;
    sf::Sprite ball;
    sf::Vector2f velocity{250.f, 250.f};
    sf::Angle angle = sf::degrees(100.f);
};