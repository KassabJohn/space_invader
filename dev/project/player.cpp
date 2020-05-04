#include "player.h"

void Player::initVariables()
{
    movementSpeed = 4.f;
    attackCooldownMax = 10.f;
    attackCooldown = attackCooldownMax;
}

void Player::initTexture()
{
    if(texture.loadFromFile("../ship.png"))
    {
        std::cout << "Texture load correctly"<<"\n";
    }
    else{
     std::cout <<"Texture : 'ship' doesn't load correctly";
    }
    }


void Player::initSprite()
{
    sprite.setTexture(this->texture);
    sprite.scale(0.1f, 0.1f);
    sprite.setPosition(750 / 2, 500);
}

Player::Player()
{
    initVariables();
    initTexture();
    initSprite();
}

Player::~Player()
{
    
}

sf::FloatRect Player::getBounds() const
{
    return sprite.getGlobalBounds();
}

const sf::Vector2f &Player::getPos() const
{
    return sprite.getPosition();
}

void Player::move(const float dirX, const float dirY)
{
    sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

 bool Player::canAttack()
{
    if(attackCooldown >= attackCooldownMax)
    {
        attackCooldown = 0.f;
        return true;
    }
    return false;
}

void Player::updateAttack()
{
    if(attackCooldown < attackCooldownMax)
    attackCooldown += 0.5f;
}

void Player::update()
{
    updateAttack();
}

void Player::render(sf::RenderTarget& target)
{
    target.draw(sprite);
}
