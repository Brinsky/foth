#include "CenteredSprite.h"

CenteredSprite::CenteredSprite(const std::string& texture_name, ResourceManager& rm) : sf::Sprite(rm.getTexture(texture_name))
{
    setOrigin(float(getTextureRect().width / 2.0), float(getTextureRect().height / 2.0));
}