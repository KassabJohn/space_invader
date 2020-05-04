#ifndef GAME_H
#define GAME_H
#include<map>
#include "player.h"
#include "bullet.h"
#include "enemy.h"

class Game
{
private :
    sf::RenderWindow* window;
    std::map<std::string, sf::Texture*> textures;
    std::vector<Bullet*> bullets;

    sf::Font font;
    sf::Text pointText;

    Player* player;
    float spawnTimer;
    float spawnTimerMax;
    std::vector<Enemy*> enemies;

    void initWindow();
    void initTextures();
    void initGUI();
    void initEnemies();
    void initPlayer();

public:
    Game();
    virtual ~Game();

    void run();

    void updatePollEvents();
    void updateInput();
    void updateGUI();
    void renderGUI();
    void updateBullets();
    void updateEnemiesAndCombat();
    void update();
    void render();
};

#endif // GAME_H
