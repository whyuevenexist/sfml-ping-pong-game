#include <Player/Player.hpp>

Player::Player(AssetManager& manager) 
    : assets(manager),
      player(assets.getTexture("assets/player.png"))          
{
    sf::FloatRect bound = player.getLocalBounds();
    player.setOrigin({(bound.position.x + bound.size.x) / 2.f, (bound.position.y + bound.size.y) / 2.f});
    player.setPosition({400.f, 600.f - bound.size.y / 2.f});
}

void Player::update(float dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A))
        player.move(sf::Vector2{-300.f, 0.f} * dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D))
        player.move(sf::Vector2{300.f, 0.f} * dt);
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(player);
}

sf::FloatRect Player::getGlobalBound() const {
    return player.getGlobalBounds();
}

void Player::setPosition(sf::Vector2f pos) {
    player.setPosition(pos);
}