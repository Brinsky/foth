#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <string>
#include <map>
#include <SFML/Graphics.hpp>

class ResourceManager
{
public:
    ResourceManager(const char* textureFilePath, const char* animationsFilePath);
    const sf::Texture& getTexture(const std::string& name);
    const std::map<std::string, sf::IntRect*>& getAnimations(const std::string& name);
    operator bool();

private:
    std::string getParentDirectory(const std::string& filePath);

    bool valid;
    struct Texture
    {
        Texture();
        Texture(const std::string& file_name);
        bool load();
        std::string file_name;
        bool loaded = false;
        sf::Texture texture;   
    };
    struct Animations
    {
        Animations();
        ~Animations();
        bool dimensioned = false;
        void setDimensions(int width, int height);
        void addAnimation(const std::string& animation_name, int x, int y,
                          bool isVertical, int frames);
        int width;
        int height;
        std::string file_name;
        std::map<std::string, sf::IntRect*> animations; 
    };
    std::map<std::string, Texture> textures;
    std::map<std::string, Animations> collectionOfAnimations;
    
    // Default values for non-existant Textures and Animations
    Texture defaultTexture;
    Animations defaultAnimations;
};

#endif