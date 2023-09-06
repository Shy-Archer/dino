#include "dino.h"
#include "game.h"
dino::dino(SDL_Renderer*renderer,int r, int g, int b) {
    this->renderer = renderer;

    this->x = 0;
    this->y = 0;
    this->w = 0;
    this->h = 0;

    this->r = r;
    this->g = g;
    this->b = b;

}
dino::dino(SDL_Renderer* renderer) {
	this->renderer = renderer;

	this->x = 0;
	this->y = 0;
	this->w = 0;
	this->h = 0;

	this->r = 0;
	this->g = 0;
	this->b = 0;

}
dino :: ~dino(){}
void dino::render() {
    SDL_Rect rect;
    rect.x = this->x;
    rect.y= this->y;
    rect.w = this->w;
    rect.h = this->h;
    SDL_SetRenderDrawColor(getrenderer(), this->r, this->g, this->b, 255);
    SDL_RenderFillRect(getrenderer(), &rect);
}
SDL_Renderer* dino::getrenderer() const{
    return renderer;
}
void dino::setX(int x) {
    this->x = x;
}
void dino::setY(int y) {
    this->y = y;
}
void dino::setW(int w) {
    this->w = w;
}
void dino::setH(int h) {
    this->h = h;
}
int dino::getX() {
    return this->x;
}
int dino::getY() {
    return this->y;
}
int dino::getW() {
    return this->w;
}
int dino::getH() {
    return this->h;
}
void dino::Gravity()
{
	if (jumpState())
	{
		accelerator1 = accelerator1 + 0.037;
		accelerator2 = accelerator2 + 0.037;
		jumpHeight = jumpHeight + gravity;
	
		this->y = this->y + gravity + accelerator1 + accelerator2 + jumpHeight;
	
		if (jumpHeight > 0)
		{
			inJump = false;
			jumpHeight = -9;
		}
	}
	else if(this->y <= 560-getH())
	{

		accelerator1 = accelerator1 + 0.037;
		accelerator2 = accelerator2 + 0.037;
		this->y = this->y + gravity + accelerator1 + accelerator2;
	
	}
	else
	{
		this->y = this->y;
		
	}

}

void dino::move()
{
	if (jumpTimer - lastJump > 180 && this->y >= 560-getH())
	{
		accelerator1 = 0;
		accelerator2 = 0;
		inJump = true;
		lastJump = jumpTimer;
	}
	else
	{
		Gravity();
	}
}

void dino::getJumpTime()
{
	jumpTimer = SDL_GetTicks();
}

bool dino::jumpState()
{
	return inJump;
}