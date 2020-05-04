#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

class Enemy
{
private:
    sf::CircleShape shape;
    int type;
    float speed;
    int hp;
    int hpMax;
    int damage;
    int points;

    void initShape();
    void initVaiables();

public:
    Enemy(float pos_x, float pos_y);
    virtual ~Enemy();

    const sf::FloatRect getBounds() const;

    void update();
    void render(sf::RenderTarget* target);
};

#endif // ENEMY_H
