#include "obstacle.h"
#include "dino.h"

obstacle::obstacle(SDL_Renderer* renderer) :dino(renderer) {
    this->renderer = renderer;

    this->x = 0;
    this->y = 0;
    this->w = 0;
    this->h = 0;

    this->r = rand() % 255;
    this->g = rand() % 255;
    this->b = rand() % 255;

}
void obstacle::render() {
    SDL_Rect rect;
    rect.x = this->x;
    rect.y = this->y;
    rect.w = this->w;
    rect.h = this->h;
    SDL_SetRenderDrawColor(getrenderer(), rand() % 255, rand() % 255, rand() % 255, 100);
    SDL_RenderFillRect(getrenderer(), &rect);
}
obstacle::~obstacle() {}
void  obstacle::move() {
    if (this->x < -4000)
    {
        this->x = 1440;
    }
    else
    {
        this->x -= speed;
      
    }
    
    
}
