#include <SFML/Graphics.hpp>

#include "image_manager.h"

ImageManager ImageManager::instance;

ImageManager::ImageManager()
{
    loadImage("img/ball_test.png", "ball");
    loadImage("img/ball_icon.png", "ballIcon");
    loadImage("img/selected_ball_test.png", "selectedBall");
    loadImage("img/main_building.png", "mainBuilding");
    loadImage("img/main_building_selected.png", "mainBuildingSelected");
    loadImage("img/cross.png", "cross");
}

ImageManager::~ImageManager()
{
    for(int i=0; i<m_textNames.size(); i++)
        delete m_images[m_textNames[i]];
}

void ImageManager::loadImage(std::string path, std::string name)
{
    sf::Texture *text = new sf::Texture();
    if(!text->loadFromFile(path))
        exit(0);
    m_images[name] = text;
    m_textNames.push_back(name);
}

sf::Texture* ImageManager::getTexture(std::string name)
{
    return m_images[name];
}

void ImageManager::setTexture(sf::Sprite sprite, std::string name)
{
    sprite.setTexture(*m_images[name]);
}
