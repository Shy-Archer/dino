#include "Game.h"


bool Game::getIsRunning() const
{
    return isRunning;
}

void Game::setIsRunning(bool value)
{
    isRunning = value;
}

SDL_Window* Game::getWindow() const
{
    return window;
}

void Game::setWindow(SDL_Window* value)
{
    window = value;
}

SDL_Renderer* Game::getRenderer() const
{
    return renderer;
}

void Game::setRenderer(SDL_Renderer* value)
{
    renderer = value;
}

int Game::getScreenWidth() const
{
    return screenWidth;
}

void Game::setScreenWidth(int value)
{
    screenWidth = value;
}

int Game::getScreenHeight() const
{
    return screenHeight;
}

void Game::setScreenHeight(int value)
{
    screenHeight = value;
}

void Game::init(const char* title, float w, float h)
{
    int flags = 0;
    screenWidth = w;
    screenHeight = h;

   
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, flags);

        renderer = SDL_CreateRenderer(window, -1,0);

        if (TTF_Init() == -1) {
            std::cout << "Couldn't initialize TrueType Font" << SDL_GetError() << std::endl;
        }

        if (renderer) {
      
            SDL_SetRenderDrawColor(renderer, 44, 47, 51, 255);

            isRunning = true;
        }
        else {
            std::cout << "Couldn't initialize renderer" << SDL_GetError() << std::endl;
        }
    }
}

Game::Game() : isRunning(false) {}