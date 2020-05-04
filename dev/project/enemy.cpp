#include "enemy.h"

void Enemy::initShape()
{
    shape.setRadius(rand() % 20 + 20);
    shape.setPointCount(rand() % 20 + 3);
    shape.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1));
}

void Enemy::initVaiables()
{
    type = 0;
    speed = 2.f;
    hp = 0;
    hpMax = 10;
    damage = 1;
    points = 5;
}

Enemy::Enemy(float pos_x, float pos_y)
{   
    initShape();
    initVaiables();
    shape.setPosition(pos_x, pos_y);
}

Enemy::~Enemy()
{

}

const sf::FloatRect Enemy::getBounds() const
{
    return shape.getGlobalBounds();
}

void Enemy::update()
{
    shape.move(0.f, speed);
}


void Enemy::render(sf::RenderTarget *target)
{
    target->draw(shape);
}
