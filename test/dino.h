#pragma once
#include <SDL.h>
class dino
{
protected:
	SDL_Renderer* renderer;
	float x, y, w, h;
	int r, g, b;
private:
	float gravity = 0.25;
	float accelerator1 = 0;
	float accelerator2 = 0;
	bool inJump = false;
	float jumpHeight = -9;
	float jumpTimer;
	float lastJump = 0;

public:
	dino(SDL_Renderer*renderer, int r, int g, int b);
	dino(SDL_Renderer* renderer);
	virtual ~dino();
	SDL_Renderer* getrenderer() const;
	virtual void render();
	virtual void move();
	void setX(int x);
	int getX();
	void setY(int y);
	int getY();
	void setW(int w);
	int getW();
	void setH(int h);
	int getH();
	void Gravity();
	void getJumpTime();
	bool jumpState();
};

