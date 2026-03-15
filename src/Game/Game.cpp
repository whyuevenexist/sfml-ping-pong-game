#include <Game/Game.hpp>
#include <iostream>

Game::Game() : player(manager), ball(manager), window(sf::VideoMode({800, 600}), "Ping-Pong") {

}

void Game::update(float dt) {
    // Основной апдейт
    player.update(dt);
    ball.update(dt);

    sf::FloatRect global_bound_player = player.getGlobalBound();
    sf::FloatRect global_bound_ball = ball.getGlobalBound();
    sf::Vector2f velocity_ball = ball.getVelocity();
    sf::Vector2f window_size = static_cast<sf::Vector2f>(window.getSize());

    // Логика коррекции позиции мяча
    if (global_bound_ball.position.x < 0 || 
        global_bound_ball.position.x + global_bound_ball.size.x > window_size.x) 
    {
        sf::Vector2f newVelocity{-velocity_ball.x, velocity_ball.y};
        ball.setVelocity(newVelocity);
    }
    if (global_bound_ball.position.y < 0 || 
        global_bound_ball.findIntersection(global_bound_player))
    {
        sf::Vector2f newVelocity{velocity_ball.x, -velocity_ball.y};
        ball.setVelocity(newVelocity);
    }

    // Логика коррекции позиции игрока
    if (global_bound_player.position.x < 0) {
        player.setPosition({(-global_bound_player.position.x + global_bound_player.size.x) / 2, (2 * global_bound_player.position.y + global_bound_player.size.y) / 2});
    }
    if (global_bound_player.position.x + global_bound_player.size.x > window_size.x)
        player.setPosition({ (2 * window_size.x - (global_bound_player.size.x + global_bound_player.position.x)) - global_bound_player.size.x / 2, (2 * global_bound_player.position.y + global_bound_player.size.y) / 2});
    // Рестарт в случае если мяч улетел 
    if (global_bound_ball.position.y + global_bound_ball.size.y > window_size.y) {
        restart();
    }
}

void Game::draw() {
    player.draw(window);
    ball.draw(window);
}

void Game::start() { 
    while(window.isOpen()) {
        sf::Time delta_t = timer.restart();
        float dt = delta_t.asSeconds();

        while (std::optional<sf::Event> event = window.pollEvent()) {

            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->code == sf::Keyboard::Key::Escape) {
                    window.close();
                }
            }
        }

        window.clear(sf::Color::Black);
        update(dt);
        draw();
        window.display();
    }
}

void Game::restart() {

}