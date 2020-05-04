#include "Game.h"

void Game::initWindow()
{
    window = new sf::RenderWindow(sf::VideoMode(800,600),"Space Shooter",sf::Style::Close | sf::Style::Titlebar);
    window->setFramerateLimit(120);
    window->setVerticalSyncEnabled(false);
}

void Game::initTextures()
{
    textures["BULLET"] = new sf::Texture();
    textures["BULLET"]->loadFromFile("../bullet.png");
}

void Game::initGUI()
{
    if(!font.loadFromFile("../ARCADECLASSIC.TTF"))
    std::cout << "Font doesnt load correctly" << "\n";

    pointText.setFont(this->font);
    pointText.setCharacterSize(40);
    pointText.setFillColor(sf::Color::White);
    pointText.setString("Space Invaders");
}

void Game::initEnemies()
{
    spawnTimerMax = 50.f;
    spawnTimer = spawnTimerMax;
}

void Game::initPlayer()
{
     player = new Player();
}

Game::Game()
{
    initWindow();
    initTextures();
    initGUI();
    initPlayer();
    initEnemies();
}

Game::~Game()
{
    delete window;
    delete player;
    for(auto &i : textures)
    {
        delete i.second;
    }
    for (auto *i : bullets)
    {
        delete i;
    }
    for (auto *i : enemies)
    {
        delete i;
    }
}



void Game::run()
{
    while(window->isOpen())
    {
    update();
    render();
    }
}

void Game::updatePollEvents()
{
    sf::Event e;
    while(window->pollEvent(e))
    {
        if(e.Event::type == sf::Event::Closed)
        window->close();
        if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Return)
            window->close();
    }
}

void Game::updateInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        player->move(-1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        player->move(1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        player->move(0.f, -1.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        player->move(0.f, 1.f);

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && player->canAttack())
    {
        bullets.push_back(new Bullet(textures["BULLET"],
        player->getPos().x + player->getBounds().width/2.3f,player->getPos().y,0.f,-1.f,5.f ));
    }
}

void Game::updateGUI()
{

}

void Game::renderGUI()
{
    window->draw(pointText);
}

void Game::updateBullets()
{
    unsigned counter = 0;
    for (auto *bullet : bullets)
    {
        bullet->update();

        if(bullet->getBounds().top + bullet->getBounds().height < 0.f)
        {
            delete bullets.at(counter);
            bullets.erase(bullets.begin()+ counter);
            -- counter;
            // pour check que toutes les bullets se delete et
            //ne reste pas en mémoire :
            //std::cout << this->bullets.size() << "\n";
        }
        ++ counter;
    }
}

void Game::updateEnemiesAndCombat()
{
    spawnTimer += 0.5f;
    if(spawnTimer >= spawnTimerMax)
    {
        enemies.push_back(new Enemy(rand()% window->getSize().x - 20.f,rand()% - 10));
        spawnTimer = 0.f;
    }
    for (unsigned int i = 0; i < enemies.size();++i)
    {
        bool enemy_removed = false;
        enemies[i]->update();
        for(size_t k = 0; k < bullets.size() && !enemy_removed; k++)
        {
            if(bullets[k]->getBounds().intersects(enemies[i]->getBounds()))
            {
                bullets.erase(bullets.begin() + k);
                enemies.erase(enemies.begin() + i);
                enemy_removed = true;
            }
        }

        if(!enemy_removed)
        if(enemies[i]->getBounds().top > window->getSize().y)
        {
            enemies.erase(enemies.begin() + i);
            // permet de check si enemie est delete une fois sortie de l'ecran :
            //std::cout << this->enemies.size() << "\n";
        }
    }

}

void Game::update()
{
    updatePollEvents();
    updateInput();
    player->update();
    updateBullets();
    updateEnemiesAndCombat();
    updateGUI();
}

void Game::render()
{
    window->clear();
    player->render(*window);
    for (auto *bullets : bullets)
    {
        bullets->render(window);
    }
    for (auto *enemy : enemies)
    {
        enemy->render(window);
    }
    renderGUI();

    window->display();

}
