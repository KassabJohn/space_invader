#include "bullet.h"

Bullet::Bullet()
{

}

Bullet::Bullet(sf::Texture * texture,float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed)
{
    shape.setTexture(*texture);
    shape.setPosition(pos_x, pos_y);
    direction.x = dir_x;
    direction.y = dir_y;
    movementSpeed = movement_speed;
}

Bullet::~Bullet()
{

}

const sf::FloatRect Bullet::getBounds() const
{
    return shape.getGlobalBounds();
}

void Bullet::update()
{
    shape.move(movementSpeed * direction);
}

void Bullet::render(sf::RenderTarget *target)
{
    target->draw(shape);
}
