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
    maxObstacles = 100;

    obstacles = new int[maxObstacles];
    for(int i=0; i<maxObstacles; ++i){
        obstacles[i] = -1; //initialiser les obstacles en dehors de la fenetre
    }

    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
}

Game::~Game(){
    delete[] obstacles;
    endwin();
}

void Game::run(){
    while(isRunning){
        handleInput();
        update();
        render();
    }
}

void Game::handleInput(){
    int ch = getch();
    switch(ch){
        case KEY_RIGHT:
            player.setX(player.getX() + 1); // Move the player right
            break;
        case KEY_LEFT:
            player.setX(player.getX() - 1); // Move the player left
            break;
        case KEY_UP:
            player.setY(player.getY() - 1); // Move the player up
            break;
        case KEY_DOWN:
            player.setY(player.getY() + 1); // Move the player up
            break;
        case 'q':
            isRunning = false; // Quit the game
            break;
        case 'Q':
            isRunning = false; // Quit the game
            break;
    }
}

void Game::update() {
    if (rand() % 10 == 0) {
        for (int i = 0; i < maxObstacles; ++i) {
            if (obstacles[i] == -1) {
                obstacles[i] = COLS-1;
                break;
            }
        }
    }

    for (int i = 0; i < maxObstacles; ++i) {
        if (obstacles[i] != -1) {
            obstacles[i]--;
        }
    }

    for (int i = 0; i < maxObstacles; ++i) {
        if (obstacles[i] >= COLS) {
            obstacles[i] = -1;
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