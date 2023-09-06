#include "Dinogame.h"
#include "Game.h"
#include "dino.h"

using namespace  std;
Dinogame::Dinogame() {
	init("Dinogame", 1440,560 );
	font = TTF_OpenFont("NotoSans-Regular.ttf", 36);
	start = TTF_OpenFont("NotoSans-Regular.ttf", 52);
	setstartY(450);
	dinosaur = new dino(getRenderer(), 66, 110, 71);
	dinosaur->setX(50);
	dinosaur->setY(getScreenHeight() - 120);
	dinosaur->setH(120);
	dinosaur->setW(80);
	for (int i = 0; i < 10; i++) {
			dino* aux = new obstacle(getRenderer());

			aux->setX(getScreenWidth() + i * 720*3);
			aux->setY(getScreenHeight()-80);
			aux->setW(60);
			aux->setH(80);

			obstacles.push_back(aux);
		}
	
	run();

}
void Dinogame::run() {
	const int FPS = 60;
	const int FRAME_DELAY = 1000 / FPS;
	unsigned int frameStart;
	unsigned int frameTime;
	while (startgame ==0 && getIsRunning())
	{
		render();
		SDL_Event event1;
		SDL_PollEvent(&event1);
		if (event1.type == SDL_QUIT)
		{
			setIsRunning(false);
		}
		if (event1.key.keysym.sym == SDLK_SPACE) {
			setstartY(2000);
			startgame = 1;
		}
	}
	while (getIsRunning()) {
		frameStart = SDL_GetTicks();
		frameTime = SDL_GetTicks() - frameStart;
		handleEvents();
		update();
		render();
		if (FRAME_DELAY > frameTime)
			SDL_Delay(FRAME_DELAY - frameTime);
	}
	clean();
}
void Dinogame::clean() {
	SDL_DestroyWindow(getWindow());
	SDL_DestroyRenderer(getRenderer());
	for (auto it = obstacles.begin(); it != obstacles.end(); ++it) {
		
		
		delete *it;

	}
	delete dinosaur;
	SDL_Quit();
}
void Dinogame::handleEvents() {
	dinosaur->getJumpTime();
	SDL_Event event1;
	SDL_PollEvent(&event1);
	if (event1.type == SDL_QUIT)
	{
		setIsRunning(false);
	}
	if (!collision()) {
		if (event1.type == SDL_KEYDOWN)
		{

			if (event1.key.keysym.sym == SDLK_UP)
			{
				if (!dinosaur->jumpState())
				{

					dinosaur->move();
					if (dinosaur->getY() >= getScreenHeight() - 120)
					{
						score++;
					
					}
			
				}
				else
				{
					dinosaur->Gravity();
				}
			}
			
			
		}

		else
		{
			dinosaur->Gravity();
		}
	}
	else
	{
		setstartY(450);
		if (event1.type == SDL_KEYDOWN)
		{
			if (event1.key.keysym.sym == SDLK_SPACE) {
				dinosaur->setX(50);
				dinosaur->setY(getScreenHeight() - 120);
				for (int i = 0; i < 10; i++) {
					obstacles[i]->setX(getScreenWidth() + i * 720 * 3);
					obstacles[i]->setY(getScreenHeight() - 80);
				}
				score = 0;
				setstartY(2000);
				run();
			}
		}
	}
}
void Dinogame::renderobs()
{
	for (auto it = obstacles.begin(); it != obstacles.end(); ++it) {
		dino* b = *it;

		b->render();
	}
}
void Dinogame::renderscore()
{
	string text = "Score: " + to_string(score);
	SDL_Color color = { 255, 255, 255, 255 };

	SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);

	SDL_Texture* texture = SDL_CreateTextureFromSurface(getRenderer(), surface);

	SDL_FreeSurface(surface);

	int textW = 0;
	int textH = 0;

	SDL_QueryTexture(texture, nullptr, nullptr, &textW, &textH);

	SDL_Rect rect = {1200, 50, textW, textH };

	SDL_RenderCopy(getRenderer(), texture, nullptr, &rect);
}
void Dinogame::renderstart()
{
	string text = "Press SPACE to start";
	SDL_Color color = { 255, 255, 255, 255 };

	SDL_Surface* surface = TTF_RenderText_Solid(start, text.c_str(), color);

	SDL_Texture* texture = SDL_CreateTextureFromSurface(getRenderer(), surface);

	SDL_FreeSurface(surface);

	int textW = 0;
	int textH = 0;

	SDL_QueryTexture(texture, nullptr, nullptr, &textW, &textH);

	SDL_Rect rect = { getstartY(), 200, textW, textH};

	SDL_RenderCopy(getRenderer(), texture, nullptr, &rect);
}

void Dinogame::render() {
	SDL_RenderClear(getRenderer());
	renderscore();
	renderstart();
	dinosaur->render();
	renderobs();
	SDL_SetRenderDrawColor(getRenderer(), 44, 47, 51, 255);
	SDL_RenderPresent(getRenderer());
}
void Dinogame::moveobs()
{
	
	for (auto it = obstacles.begin(); it != obstacles.end(); ++it) {
		dino* b = *it;
	
		
		b->move();
		
	
	}
}
void Dinogame::update() {
	if (!collision()) {
		moveobs();
	}
}
bool Dinogame::collision() {
	for (auto it = obstacles.begin(); it != obstacles.end(); ++it) { 
		dino* aux = *it;

		if (dinosaur->getX() + dinosaur->getW() > aux->getX() && dinosaur->getX() < aux->getX() + aux->getW()
			&& dinosaur->getY() + dinosaur->getH() > aux->getY() && dinosaur->getY() < aux->getY() + aux->getH()) {
			return true;
		}
		
	}
	return false;
}
void Dinogame::setstartY(int i) {
	startY = i;
}
int Dinogame::getstartY() {
	return startY;
}