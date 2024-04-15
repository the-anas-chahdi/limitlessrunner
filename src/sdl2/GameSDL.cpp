/**
 * @file GameSDL.cpp
 * @author damiyine loubna - anas chahdi
 * @brief
 * @version 0.1
 * @date 2024-04-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "GameSDL.h"
#include "Drawing.h"
#include "ScreenInfo.h"
#include "RunningPlayer.h"

SDL_Renderer *Drawing::gRenderer = nullptr;
SDL_Texture *Drawing::assets = nullptr;
SDL_Texture *Drawing::tt = nullptr;
SDL_Texture *Drawing::life = nullptr;
SDL_Texture *Drawing::Ghost = nullptr;
SDL_Texture *Drawing::Meteor = nullptr;
SDL_Texture *Drawing::exp = nullptr;

ScreenInfo *ScreenInfo::instance = 0;

ScreenInfo *screen = screen->getInstance();
/**
 * @brief Initialise SDL et crée la fenêtre du jeu
 */
bool GameSDL::init()
{
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            printf("Warning: Linear texture filtering not enabled!");
        }

        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
        {
            printf("Unable to open audio: %s\n", Mix_GetError());
            success = false;
        }

        gWindow = SDL_CreateWindow("Limitless Runner", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen->getWidth(), screen->getHeight(), SDL_WINDOW_SHOWN);
        if (gWindow == nullptr)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            Drawing::gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (Drawing::gRenderer == nullptr)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                SDL_SetRenderDrawColor(Drawing::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }
            }
        }
    }

    return success;
}
/** @brief Charge les textures nécessaires pour le jeu
 */
bool GameSDL::loadGrid()
{
    bool success = true;
    Drawing::assets = loadTexture("assets/assets.png");
    Drawing::exp = loadTexture("assets/exp.png");
    Drawing::tt = loadTexture("assets/tt.png");
    Drawing::life = loadTexture("assets/life.png");
    Drawing::Ghost = loadTexture("assets/ghost.png");
    Drawing::Meteor = loadTexture("assets/meteor.png");
    gTexture = loadTexture("assets/bg.png");
    if (Drawing::assets == NULL || Drawing::tt == NULL || Drawing::life == NULL || Drawing::Ghost == NULL || Drawing::Meteor == NULL || gTexture == NULL)
    {
        printf("Unable to run due to error: %s\n", SDL_GetError());
        success = false;
    }
    return success;
}

bool GameSDL::loadMedia()
{

    bool success = true;
    music = Mix_LoadMUS("assets/music.mp3");
    gTexture = loadTexture("assets/menu.png");
    if (gTexture == NULL)
    {
        printf("Unable to run due to error: %s\n", SDL_GetError());
        success = false;
    }
    if (music == NULL)
    {
        printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }
    Mix_PlayMusic(music, 0);
    return success;
}

bool GameSDL::loadIns()
{
    bool success = true;
    gTexture = loadTexture("assets/instructions.png");
    if (gTexture == NULL)
    {
        printf("Unable to run due to error: %s\n", SDL_GetError());
        success = false;
    }
    return success;
}

bool GameSDL::loadWIN()
{
    bool success = true;
    gTexture = loadTexture("assets/won.png");
    if (gTexture == NULL)
    {
        printf("Unable to run due to error: %s\n", SDL_GetError());
        success = false;
    }
    return success;
}

bool GameSDL::loadLOST()
{
    bool success = true;
    gTexture = loadTexture("assets/lost.png");
    if (gTexture == NULL)
    {
        printf("Unable to run due to error: %s\n", SDL_GetError());
        success = false;
    }
    return success;
}

void GameSDL::close()
{
    SDL_DestroyTexture(Drawing::assets);
    Drawing::assets = NULL;
    SDL_DestroyTexture(Drawing::tt);
    Drawing::tt = NULL;
    SDL_DestroyTexture(Drawing::life);
    Drawing::life = NULL;
    SDL_DestroyTexture(Drawing::Ghost);
    Drawing::Ghost = NULL;
    SDL_DestroyTexture(Drawing::Meteor);
    Drawing::Meteor = NULL;
    SDL_DestroyTexture(Drawing::exp);
    Drawing::exp = NULL;
    SDL_DestroyTexture(gTexture);

    SDL_DestroyRenderer(Drawing::gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    Drawing::gRenderer = NULL;
    IMG_Quit();
    SDL_Quit();
}

SDL_Texture *GameSDL::loadTexture(std::string path)
{
    SDL_Texture *newTexture = NULL;

    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        newTexture = SDL_CreateTextureFromSurface(Drawing::gRenderer, loadedSurface);
        if (newTexture == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}

void GameSDL::run()
{
    bool quit = false;
    SDL_Event e;

    RunningPlayer runningPlayer;

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {

            if (e.type == SDL_QUIT)
            {
                quit = true;
                cout << quit;
            }

            if (e.type == SDL_MOUSEBUTTONDOWN)
            {

                int xMouse, yMouse;
                SDL_GetMouseState(&xMouse, &yMouse);
                if (state == 0 and xMouse >= 415 and xMouse <= 575 and yMouse >= 245 and yMouse <= 295)
                {
                    state = 2;
                    loadGrid();
                }
                else if (state == 4)
                {
                    if (xMouse >= 425 and xMouse <= 575 and yMouse >= 480 and yMouse <= 535)
                    {
                        quit = true;
                    }
                    else if (xMouse >= 410 and xMouse <= 590 and yMouse >= 400 and yMouse <= 470)
                    {
                        state = 0;
                        runningPlayer.counter = 0;
                        loadMedia();
                    }
                }
                else if (state == 0 and xMouse >= 360 and xMouse <= 630 and yMouse >= 370 and yMouse <= 425)
                {
                    state = 1;
                    loadIns();
                }
                else if (state == 1 and xMouse >= 40 and xMouse <= 145 and yMouse >= 35 and yMouse <= 85)
                {
                    state = 0;
                    loadMedia();
                }
            }
            const Uint8 *state = SDL_GetKeyboardState(NULL);
            if (state[SDL_SCANCODE_UP])
            {
                runningPlayer.checks = true;
            }
            if (state[SDL_SCANCODE_RIGHT])
            {
                runningPlayer.right = true;
            }
            if (state[SDL_SCANCODE_LEFT])
            {
                runningPlayer.left = true;
            }
        }
        if (runningPlayer.win_check)
        {
            loadWIN();
            runningPlayer.emptying();
            state = 4;
            runningPlayer.win_check = false;
        }
        if (runningPlayer.lost_check)
        {
            loadLOST();
            runningPlayer.emptying();
            state = 4;
            runningPlayer.lost_check = false;
        }

        SDL_RenderClear(Drawing::gRenderer);
        SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL);

        if (state == 2)
        {
            runningPlayer.drawObjects();
            runningPlayer.createObject();
        }

        SDL_RenderPresent(Drawing::gRenderer);

        SDL_Delay(60);
    }
}