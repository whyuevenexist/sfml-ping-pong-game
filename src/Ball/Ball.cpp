#include <Ball/Ball.hpp>

Ball::Ball(AssetManager& manager) 
    : assets(manager),
      ball(assets.getTexture("assets/ball.png"))
{
    sf::FloatRect bound = ball.getLocalBounds();
    ball.setOrigin({bound.size.x / 2.f, bound.size.y / 2.f});
    ball.setPosition({400.f, 300.f});
}

void Ball::update(float dt) {
    ball.rotate(angle * dt);
    ball.move(velocity * dt);
}

void Ball::draw(sf::RenderWindow& window) {
    window.draw(ball);
}

sf::FloatRect Ball::getGlobalBound() const {
    return ball.getGlobalBounds();
}

sf::Vector2f Ball::getVelocity() const {
    return velocity;
}

sf::Vector2f Ball::setVelocity(sf::Vector2f newVelocity) {
    return velocity = newVelocity;
}