/**
 * @file Game.cpp
 * @author damiyine loubna - anas chahdi
 * @brief 
 * @version 0.1
 * @date 2024-04-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include "Game.h"
#include <ncurses.h>
#include <cstdlib>
#include "Player.h"
#include <chrono>
#include <thread>

using namespace std;

Game::Game() {
    /**
 * @brief 
 * Libère la mémoire alloue dynamiquement et nettoie ncurses à la fin du jeu
 */
    initscr();
    if (LINES < 3 || COLS < 3) {
        endwin();
        cout << "Terminal window size is too small!" << endl;
        exit(EXIT_FAILURE);
    }
    isRunning = true;
    player = Player(2, LINES - 2, 10);
    maxObstacles = 20;
    obstacles = new Obstacle[maxObstacles];
    isJumping = false;
    canDoubleJump = false; // Initialize the ability to double jump
    jumpVelocity = 0;
    gravity = 1;
    score = 0;
    for(int i=0; i<maxObstacles; ++i){
        //initialiser les obstacles en dehors de la fenetre
        obstacles[i].setX(-1);
        obstacles[i].setY(LINES-2);
    }

    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    nodelay(stdscr, TRUE);
}

Game::~Game(){
    delete[] obstacles;
    endwin();
}

void Game::run(){
    /** @brief Vérifie les collisions et met à jour la position des obstacles et du joueur et traite l'entrée utilisateur
 */
    std::chrono::steady_clock::time_point lastTime = std::chrono::steady_clock::now();
    while(isRunning){
        std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();
        std::chrono::milliseconds elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastTime);

        update();
        render();

        std::this_thread::sleep_for(std::chrono::milliseconds(50 - elapsedTime.count()));

        lastTime = currentTime;
        score++;
    }
}

void Game::update() {
    checkCollisions();

    /**
     * @brief update les obstacles 

     */
    for (int i = 0; i < maxObstacles; ++i) {
        if (obstacles[i].getX() != -1) {
            obstacles[i].setX(obstacles[i].getX() - 1);
            if (obstacles[i].getX() < 0) {
                obstacles[i].setX(COLS - 1);
            }
        }
    }

    if (rand() % 20 == 0) {
        int index = rand() % maxObstacles;
        if (obstacles[index].getX() == -1 &&
            (index == 0 || obstacles[index - 1].getX() < COLS - 15)) {
            obstacles[index].setX(COLS - 1);
        }
    }

    if (isJumping) {
        player.setY(player.getY() - jumpVelocity);
        jumpVelocity--;

        if (jumpVelocity < -2) {
            isJumping = false;
            jumpVelocity = 4;
        }
    } else {
        int newY = player.getY() + gravity;

        if (newY >= LINES - 2) {
            player.setY(LINES - 2);
            canDoubleJump = true; 
        } else {
            player.setY(newY);
        }
    }

    int ch = getch();
    if (ch != ERR) {
        switch (ch) {
            case KEY_RIGHT:
                player.setX(player.getX() + 1);
                break;
            case KEY_LEFT:
                player.setX(player.getX() - 1);
                break;
            case KEY_UP:
                if (!isJumping) {
                    isJumping = true;
                    jumpVelocity = 4;
                } else if (canDoubleJump) { 
                    jumpVelocity = 4;
                    canDoubleJump = false; 
                }
                break;
            case KEY_DOWN:
                player.setY(player.getY() + 1);
                break;
            case 'q':
            case 'Q':
                isRunning = false;
                break;
        }
    }
}

void Game::render() {
    /**
     * @brief affichage du joueur score et ostacle
     
     */
    clear();
    mvaddch(player.getY(), player.getX(), 'P');

    for (int i = 0; i < maxObstacles; ++i) {
        if (obstacles[i].getX() >= 0 && obstacles[i].getX() < COLS) {
            mvaddch(LINES - 2, obstacles[i].getX(), '*');
        }
    }
    mvhline(0, 0, '-', COLS);
    mvprintw(0, COLS - 10, "Lives: %d", player.getLives());
    mvprintw(0, 1, "Score: %d", score);

    refresh();
}

void Game::checkCollisions() {
    int playerX = player.getX();
    int playerY = player.getY();

    for (int i = 0; i < maxObstacles; ++i) {
        /**
         * @brief Pas besoin de continuer à vérifier les collisions si le joueur est à court de vies
         
         */
        if (obstacles[i].getX() != -1 && obstacles[i].getX() == playerX && playerY == LINES - 2) {
            player.loseLife();
            if (player.getLives() <= 0) {
                isRunning = false;
                break;  
            }
        }
    }
}
