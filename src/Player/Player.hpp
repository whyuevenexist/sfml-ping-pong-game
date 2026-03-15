#pragma once

#include <SFML/Graphics.hpp>
#include <AssetManager/AssetManager.hpp>

class Player {
public:
    Player(AssetManager& manager);

    void update(float dt);

    void draw(sf::RenderWindow& window);

    sf::FloatRect getGlobalBound() const;

    void setPosition(sf::Vector2f pos);
private:
    AssetManager& assets;
    sf::Sprite player;
};