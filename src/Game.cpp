//
// Created by anasc on 25/03/2024.
//
#include "Game.h"
#include <ncurses.h>
#include <cstdlib>
#include "Player.h"

using namespace std;

Game::Game() {
    initscr();
    if (LINES < 3 || COLS < 3) {
        endwin();
        cout << "Terminal window size is too small!" << endl;
        exit(EXIT_FAILURE);
    }
    isRunning = true;
    player = Player(2, LINES - 2);
    maxObstacles = 50;
    isJumping = false;
    gravity = 1;

    obstacles = new int[maxObstacles];
    for(int i=0; i<maxObstacles; ++i){
        obstacles[i] = -1; //initialiser les obstacles en dehors de la fenetre
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
    while(isRunning){
        update();
        render();
        napms(50);
    }
}

void Game::update() {
    for (int i = 0; i < maxObstacles; ++i) {
        if (obstacles[i] != -1) {
            obstacles[i]--;
            if (obstacles[i] < 0) {
                obstacles[i] = COLS - 1;
            }
        }
    }

    if (rand() % 10 == 0) {
        for (int i = 0; i < maxObstacles; ++i) {
            if (obstacles[i] == -1) {
                // verifier l'espacement
                int spacing = rand() % (COLS / 4);
                bool isValid = true;
                for (int j = max(0, i - spacing); j < i; ++j) {
                    if (obstacles[j] != -1 && obstacles[j] > COLS - spacing) {
                        isValid = false;
                        break;
                    }
                }
                if (isValid) {
                    obstacles[i] = COLS - 1;
                    break;
                }
            }
        }
    }

    if (isJumping) {
        player.setY(player.getY() - jumpVelocity);
        jumpVelocity--;

        if (jumpVelocity < -2) {
            isJumping = false;
            jumpVelocity = 2;
        }
    } else {
        int newY = player.getY() + gravity;

        // verifier la collision avec le sol
        if (newY >= LINES - 2) {
            player.setY(LINES - 2);
        } else {
            player.setY(newY);
        }
    }

    int ch = getch();
    if(ch != ERR) {
        switch(ch){
            case KEY_RIGHT:
                player.setX(player.getX() + 1);
                break;
            case KEY_LEFT:
                player.setX(player.getX() - 1);
                break;
            case KEY_UP:
                if (!isJumping) {
                    isJumping = true;
                    jumpVelocity = 2;
                } else {
                    jumpVelocity *= 2; //super jump
                }
                break;
            case KEY_DOWN:
                player.setY(player.getY() + 1);
                break;
            case 'q':
                isRunning = false;
                break;
            case 'Q':
                isRunning = false;
                break;
        }
    }

}

void Game::render() {
    clear();
    mvaddch(player.getY(), player.getX(), 'P');
    for (int i = 0; i < maxObstacles; ++i) {
        if (obstacles[i] != -1 && obstacles[i] < COLS) {
            mvaddch(LINES - 2, obstacles[i], '*');
        }
    }
    mvhline(0, 0, '-', COLS);
    refresh();
}