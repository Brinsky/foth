#ifndef MANAGEDSPRITE_H
#define MANAGEDSPRITE_H

#include <string>
#include <SFML/Graphics.hpp>
#include "ResourceManager.h"

class ManagedSprite : public sf::Sprite
{
    public:
        ManagedSprite(ResourceManager& manager, const std::string& name, bool isCentered = false);
        ManagedSprite(ResourceManager& manager, const std::string& name, const sf::IntRect& rectangle, bool isCentered = false);
        void setTextureRect(const sf::IntRect& rectangle); 
    private:
        bool isCentered;        
};

#endif
