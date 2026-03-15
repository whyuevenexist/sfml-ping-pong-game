#pragma once 

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class AssetManager {
public:
    AssetManager() = default;

    sf::Texture& getTexture(const std::string& path);
private:
    std::map<std::string, sf::Texture> textures;
};