//
// Created by anasc on 25/03/2024.
//
#include <iostream>
#include "Game.h"
#include "Player.h"

using namespace std;

class Game {
private:
    bool isRunning;
    Player player;
    int maxObstacles;
    int* obstacles;

    void update(){
        cout << "Màj" << endl;
    }

public:
    Game() {
        isRunning = true;
        player = Player(0, 0);
        maxObstacles = 100;
        obstacles = new int[maxObstacles];
        for(int i=0; i<maxObstacles; ++i){
            obstacles[i] = -1; //initialiser les obstacles en dehors de la fenetre
        }
    }

    ~Game(){
        delete[] obstacles;
    }

    void run(){
        while(isRunning){
            handleInput();
            update();
        }
    }

    void handleInput(){

    }
};