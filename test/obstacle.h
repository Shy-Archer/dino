#pragma once
#include "dino.h"
#include <iostream>
class obstacle : public dino
{private:
	float speed = 12;
public:
	obstacle(SDL_Renderer* renderer);
	void render();
	~obstacle();
	void move();
};

