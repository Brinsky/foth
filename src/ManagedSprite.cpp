#include "ManagedSprite.h"

ManagedSprite::ManagedSprite(ResourceManager& manager,
const std::string& textureName,
bool isCentered) : sf::Sprite(manager.getTexture(textureName))
{
    this->isCentered = isCentered;
    if (isCentered)   
        setOrigin(float(getTextureRect().width / 2.0),
                  float(getTextureRect().height / 2.0));
}

ManagedSprite::ManagedSprite(ResourceManager& manager,
const std::string& textureName,
const sf::IntRect& rectangle,
bool isCentered) : sf::Sprite(manager.getTexture(textureName))
{
    this->isCentered = isCentered;
    if (isCentered)   
        setOrigin(float(getTextureRect().width / 2.0),
                  float(getTextureRect().height / 2.0));
    setTextureRect(rectangle);
}

void ManagedSprite::setTextureRect(const sf::IntRect& rectangle)
{
    Sprite::setTextureRect(rectangle);
    if (isCentered)   
        setOrigin(float(getTextureRect().width / 2.0),
                  float(getTextureRect().height / 2.0));
    else 
        setOrigin(float(getTextureRect().left),
                  float(getTextureRect().top));        
}
