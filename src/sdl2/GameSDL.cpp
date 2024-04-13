//
// Created by anas on 13/04/24.
//

#include "GameSDL.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <SDL2/SDL_image.h>

// Constants
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int PLAYER_SIZE = 10;
const int OBSTACLE_SIZE = 10;
const int GROUND_HEIGHT = 2;
const int MAX_OBSTACLES = 50;

GameSDL::GameSDL() {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Limitless Runner SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    isRunning = true;
    player = PlayerSDL(2, WINDOW_HEIGHT - 2, 3);
    maxObstacles = MAX_OBSTACLES;
    isJumping = false;
    gravity = 1;

    obstacles = new int[maxObstacles];
    for (int i = 0; i < maxObstacles; ++i) {
        obstacles[i] = -1; // initialize obstacles outside the window
    }

    srand(time(NULL));

    backgroundTexture = loadTexture("src/assets/bg.png");
    if (backgroundTexture == nullptr) {
        std::cerr << "Failed to load background image! Exiting..." << std::endl;
        exit(EXIT_FAILURE);
    }
}

GameSDL::~GameSDL() {
    delete[] obstacles;
    SDL_DestroyTexture(backgroundTexture);
    // Free other textures if used
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

SDL_Texture* GameSDL::loadTexture(const std::string& filePath) {
    // Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(filePath.c_str());
    if (loadedSurface == nullptr) {
        std::cerr << "Unable to load image " << filePath << "! SDL_image Error: " << IMG_GetError() << std::endl;
        exit(EXIT_FAILURE); // Exit the program if loading fails
    }

    // Create texture from surface pixels
    SDL_Texture* newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (newTexture == nullptr) {
        std::cerr << "Unable to create texture from " << filePath << "! SDL Error: " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE); // Exit the program if creation fails
    }

    // Get rid of old loaded surface
    SDL_FreeSurface(loadedSurface);

    return newTexture;
}

void GameSDL::run() {
    while (isRunning) {
        update();
        render();
        SDL_Delay(50);
    }
}

void GameSDL::update() {
    checkCollisions();

    for (int i = 0; i < maxObstacles; ++i) {
        if (obstacles[i] != -1) {
            obstacles[i]--;
            if (obstacles[i] < 0) {
                obstacles[i] = WINDOW_WIDTH - 1;
            }
        }
    }

    if (rand() % 20 == 0) {
        for (int i = 0; i < maxObstacles; ++i) {
            if (obstacles[i] == -1) {
                // check spacing
                int spacing = rand() % (WINDOW_WIDTH / 4);
                bool isValid = true;
                for (int j = std::max(0, i - spacing); j < i; ++j) {
                    if (obstacles[j] != -1 && obstacles[j] > WINDOW_WIDTH - spacing) {
                        isValid = false;
                        break;
                    }
                }
                if (isValid && (i == 0 || obstacles[i - 1] == -1 || obstacles[i - 1] < WINDOW_WIDTH - 4 || (obstacles[i - 1] > WINDOW_WIDTH - 4 && obstacles[i - 1] < WINDOW_WIDTH - 1))) {
                    obstacles[i] = WINDOW_WIDTH - 1;
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

        // check collision with ground
        if (newY >= WINDOW_HEIGHT - GROUND_HEIGHT) {
            player.setY(WINDOW_HEIGHT - GROUND_HEIGHT);
        } else {
            player.setY(newY);
        }
    }
}

void GameSDL::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Render background
    SDL_Rect bgRect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
    SDL_RenderCopy(renderer, backgroundTexture, NULL, &bgRect);

    // Render player
    SDL_Rect playerRect = { player.getX(), player.getY(), PLAYER_SIZE, PLAYER_SIZE };
    SDL_RenderCopy(renderer, playerTexture, NULL, &playerRect);

    // Render obstacles
    for (int i = 0; i < maxObstacles; ++i) {
        if (obstacles[i] != -1 && obstacles[i] < WINDOW_WIDTH) {
            SDL_Rect obstacleRect = { obstacles[i], WINDOW_HEIGHT - GROUND_HEIGHT, OBSTACLE_SIZE, OBSTACLE_SIZE };
            SDL_RenderCopy(renderer, obstacleTexture, NULL, &obstacleRect);
        }
    }

    SDL_RenderPresent(renderer);
}

void GameSDL::checkCollisions() {
    for (int i = 0; i < maxObstacles; ++i) {
        if (obstacles[i] != -1 && obstacles[i] == player.getX() && player.getY() == WINDOW_HEIGHT - GROUND_HEIGHT) {
            player.loseLife();
            if (player.getLives() <= 0) {
                isRunning = false;
            }
        }
    }
}
