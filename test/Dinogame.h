#pragma once
#include <SDL.h>
#include "Game.h"
#include "dino.h"
#include <vector>
#include "obstacle.h"
#include <iostream>
#include <string>
class Dinogame : public Game
{
private:
	std::vector<dino*>obstacles;
	dino* dinosaur;
	bool collision();
	int score =0;
	int startgame = 0;
	TTF_Font* font;
	TTF_Font* start;
	int startY;
	void run();
	void renderobs();
	void moveobs();
	void renderscore();
	void renderstart();
	void clean();
	void handleEvents();
	void update();
	void render();
	
public:
	Dinogame();
	void setstartY(int i);
	int getstartY();



};

