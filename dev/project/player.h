#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

class Player
{
private:
    sf::Sprite sprite;
    sf::Texture texture;
    
    float movementSpeed;

    float attackCooldown;
    float attackCooldownMax;

    void initVariables();
    void initTexture();
    void initSprite();

public:
    Player();
    virtual ~Player();
    sf::FloatRect getBounds() const;

    const sf::Vector2f& getPos() const;
    void move(const float dirX, const float dirY);
    bool canAttack();
    void updateAttack();
    void update();
    void render(sf::RenderTarget& target);
};

#endif // PLAYER_H
