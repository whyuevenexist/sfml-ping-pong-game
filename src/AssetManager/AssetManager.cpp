#include <AssetManager/AssetManager.hpp>
#include <SFML/Graphics.hpp>
#include <stdexcept>

sf::Texture& AssetManager::getTexture(const std::string& path) {
    auto it = textures.find(path);

    if (it != textures.end()) {
        return it->second;
    }

    sf::Texture& tex = textures[path];

    if (!tex.loadFromFile(path)) {
        textures.erase(path);
        throw std::runtime_error("Не удалось найти текстуру по пути:" + path);
    }
    
    return tex;
}