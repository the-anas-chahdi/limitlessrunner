//
// Created by anasc on 25/03/2024.
//
#include <iostream>
#include "Game.h"

using namespace std;

class Game {
public:
    void run(){
        while(isRunning){
            update();
        }
    }
private:
    bool isRunning = true;
    void update(){
        cout << "Màj" << endl;
    }
};