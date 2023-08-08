#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <vector>

#include "RenderWindow.h"
#include "Entity.h"
#include "Ball.h"
#include "Tile.h"
#include "Hole.h"

bool init()
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;
	if (!(TTF_Init()))
		std::cout << "TTF_init has failed. Error: " << SDL_GetError() << std::endl;
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	return true;
}

bool SDLinit = init();

SDL_Renderer* renderer;

RenderWindow window("Golfin' Around", 640, 480);

SDL_Texture* ball = window.loadTexture("res/gfx/ball.png");
SDL_Texture* Aplus = window.loadTexture("res/gfx/A+.png");
SDL_Texture* penguin = window.loadTexture("res/gfx/penguin.png");
SDL_Texture* tvhsv = window.loadTexture("res/gfx/tvhsv.png");
SDL_Texture* japit = window.loadTexture("res/gfx/japit.png");
SDL_Texture* anya = window.loadTexture("res/gfx/anya.png");

SDL_Texture* holeTexture = window.loadTexture("res/gfx/hole.png");
SDL_Texture* pointTexture = window.loadTexture("res/gfx/point.png");

/**tiles**/
SDL_Texture* tileDarkTexture32_1 = window.loadTexture("res/gfx/tile32_dark_1.png");
SDL_Texture* tileDarkTexture32_2 = window.loadTexture("res/gfx/tile32_dark_2.png");
SDL_Texture* tileDarkTexture32_3 = window.loadTexture("res/gfx/tile32_dark_3.png");
SDL_Texture* tileDarkTexture32_4 = window.loadTexture("res/gfx/tile32_dark_4.png");
SDL_Texture* tileDarkTexture32_5 = window.loadTexture("res/gfx/tile32_dark_5.png");
SDL_Texture* tileDarkTexture32_6 = window.loadTexture("res/gfx/tile32_dark_6.png");
SDL_Texture* tileDarkTexture32_7 = window.loadTexture("res/gfx/tile32_dark_7.png");
SDL_Texture* tileDarkTexture32_8 = window.loadTexture("res/gfx/tile32_dark_8.png");
SDL_Texture* tileDarkTexture32_9 = window.loadTexture("res/gfx/tile32_dark_9.png");
SDL_Texture* tileDarkTexture32_10 = window.loadTexture("res/gfx/tile32_dark_10.png");

SDL_Texture* tileDarkTexture64_1 = window.loadTexture("res/gfx/tile64_dark_1.png");
SDL_Texture* tileDarkTexture64_2 = window.loadTexture("res/gfx/tile64_dark_2.png");
SDL_Texture* tileDarkTexture64_3 = window.loadTexture("res/gfx/tile64_dark_3.png");
SDL_Texture* tileDarkTexture64_4 = window.loadTexture("res/gfx/tile64_dark_4.png");
SDL_Texture* tileDarkTexture64_5 = window.loadTexture("res/gfx/tile64_dark_5.png");
SDL_Texture* tileDarkTexture64_6 = window.loadTexture("res/gfx/tile64_dark_6.png");
SDL_Texture* tileDarkTexture64_7 = window.loadTexture("res/gfx/tile64_dark_7.png");
SDL_Texture* tileDarkTexture64_8 = window.loadTexture("res/gfx/tile64_dark_8.png");
SDL_Texture* tileDarkTexture64_9 = window.loadTexture("res/gfx/tile64_dark_9.png");
SDL_Texture* tileDarkTexture64_10 = window.loadTexture("res/gfx/tile64_dark_10.png");

SDL_Texture* tileLightTexture32_1 = window.loadTexture("res/gfx/tile32_light_1.png");
SDL_Texture* tileLightTexture32_2 = window.loadTexture("res/gfx/tile32_light_2.png");
SDL_Texture* tileLightTexture32_3 = window.loadTexture("res/gfx/tile32_light_3.png");
SDL_Texture* tileLightTexture32_4 = window.loadTexture("res/gfx/tile32_light_4.png");
SDL_Texture* tileLightTexture32_5 = window.loadTexture("res/gfx/tile32_light_5.png");
SDL_Texture* tileLightTexture32_6 = window.loadTexture("res/gfx/tile32_light_6.png");
SDL_Texture* tileLightTexture32_7 = window.loadTexture("res/gfx/tile32_light_7.png");
SDL_Texture* tileLightTexture32_8 = window.loadTexture("res/gfx/tile32_light_8.png");
SDL_Texture* tileLightTexture32_9 = window.loadTexture("res/gfx/tile32_light_9.png");
SDL_Texture* tileLightTexture32_10 = window.loadTexture("res/gfx/tile32_light_10.png");

SDL_Texture* tileLightTexture64_1 = window.loadTexture("res/gfx/tile64_light_1.png");
SDL_Texture* tileLightTexture64_2 = window.loadTexture("res/gfx/tile64_light_2.png");
SDL_Texture* tileLightTexture64_3 = window.loadTexture("res/gfx/tile64_light_3.png");
SDL_Texture* tileLightTexture64_4 = window.loadTexture("res/gfx/tile64_light_4.png");
SDL_Texture* tileLightTexture64_5 = window.loadTexture("res/gfx/tile64_light_5.png");
SDL_Texture* tileLightTexture64_6 = window.loadTexture("res/gfx/tile64_light_6.png");
SDL_Texture* tileLightTexture64_7 = window.loadTexture("res/gfx/tile64_light_7.png");
SDL_Texture* tileLightTexture64_8 = window.loadTexture("res/gfx/tile64_light_8.png");
SDL_Texture* tileLightTexture64_9 = window.loadTexture("res/gfx/tile64_light_9.png");
SDL_Texture* tileLightTexture64_10 = window.loadTexture("res/gfx/tile64_light_10.png");

/*****/
SDL_Texture* ballShadowTexture = window.loadTexture("res/gfx/ball_shadow.png");
SDL_Texture* bgTextureLight = window.loadTexture("res/gfx/bg_light.png");
SDL_Texture* uiBgTexture = window.loadTexture("res/gfx/UI_bg.png");
SDL_Texture* levelTextBgTexture = window.loadTexture("res/gfx/levelText_bg.png");
SDL_Texture* powerMeterTexture_FG = window.loadTexture("res/gfx/powermeter_fg.png");
SDL_Texture* powerMeterTexture_BG = window.loadTexture("res/gfx/powermeter_bg.png");
SDL_Texture* powerMeterTexture_overlay = window.loadTexture("res/gfx/powermeter_overlay.png");
SDL_Texture* title_BG  = window.loadTexture("res/gfx/title_bg.png");
SDL_Texture* logoSDL = window.loadTexture("res/gfx/sdl.png");
SDL_Texture* logoTexture = window.loadTexture("res/gfx/logo.png");
SDL_Texture* click2start = window.loadTexture("res/gfx/click2start.png");
SDL_Texture* endscreenOverlayTexture = window.loadTexture("res/gfx/end.png");
SDL_Texture* splashBgTexture = window.loadTexture("res/gfx/splashbg.png");
SDL_Texture* helpMenu = window.loadTexture("res/gfx/help.png");
SDL_Texture* chooseBallMenu = window.loadTexture("res/gfx/chooseBall.png");
SDL_Texture* loseScreen = window.loadTexture("res/gfx/lose.png");

SDL_Texture* playWhenHovered = window.loadTexture("res/gfx/play_hovered.png");
SDL_Texture* helpWhenHovered = window.loadTexture("res/gfx/help_hovered.png");

SDL_Texture* sand32 = window.loadTexture("res/gfx/sand32.png");
SDL_Texture* ice32 = window.loadTexture("res/gfx/ice32.png");
SDL_Texture* sand64 = window.loadTexture("res/gfx/sand64.png");
SDL_Texture* ice64 = window.loadTexture("res/gfx/ice64.png");
SDL_Texture* waterTexture64 = window.loadTexture("res/gfx/water_64.png");
SDL_Texture* waterTexture32 = window.loadTexture("res/gfx/water_32.png");
SDL_Texture* spring64 = window.loadTexture("res/gfx/spring64.png");
SDL_Texture* spring32 = window.loadTexture("res/gfx/spring32.png");

Mix_Chunk* chargeSfx = Mix_LoadWAV("res/sfx/charge.mp3");
Mix_Chunk* swingSfx = Mix_LoadWAV("res/sfx/swing.mp3");
Mix_Chunk* holeSfx = Mix_LoadWAV("res/sfx/hole.mp3");
Mix_Chunk* waterSfx = Mix_LoadWAV("res/sfx/water.mp3");
Mix_Chunk* bounceSfx = Mix_LoadWAV("res/sfx/bounce.mp3");
Mix_Chunk* openingSfx = Mix_LoadWAV("res/sfx/SUPERCELL.mp3");
Mix_Chunk* loseSfx = Mix_LoadWAV("res/sfx/lose.mp3");
Mix_Chunk* winSfx = Mix_LoadWAV("res/sfx/win.mp3");

Mix_Music* lobbyMusic = Mix_LoadMUS("res/sfx/SPYxFAMILY.mp3");


SDL_Color white = { 255, 255, 255 };
SDL_Color black = { 0, 0, 0 };
TTF_Font* font32 = TTF_OpenFont("res/font/font.ttf", 32);
TTF_Font* font48 = TTF_OpenFont("res/font/font.ttf", 48);
TTF_Font* font24 = TTF_OpenFont("res/font/font.ttf", 24);

Ball balls[2] = {Ball(Vector2f(0, 0), ballTexture, pointTexture, powerMeterTexture_FG, powerMeterTexture_BG, 0), Ball(Vector2f(0, 0), ballTexture, pointTexture, powerMeterTexture_FG, powerMeterTexture_BG, 1)};
std::vector<Hole> holes = {Hole(Vector2f(0, 0), holeTexture), Hole(Vector2f(0, 0), holeTexture)};

std::vector<Tile> loadTiles(int level)
{
	std::vector<Tile> temp = {};
	switch(level)
	{
		case 0:
			temp.push_back(Tile(Vector2f(64*3, 64*3), tileDarkTexture64));
			temp.push_back(Tile(Vector2f(64*4, 64*3), tileDarkTexture64));

			temp.push_back(Tile(Vector2f(64*0, 64*3), tileDarkTexture64));
			temp.push_back(Tile(Vector2f(64*1, 64*3), tileDarkTexture64));

			temp.push_back(Tile(Vector2f(64*3 + 64*5, 64*3), tileLightTexture64));
			temp.push_back(Tile(Vector2f(64*4 + 64*5, 64*3), tileLightTexture64));

			temp.push_back(Tile(Vector2f(64*0 + 64*5, 64*3), tileLightTexture64));
			temp.push_back(Tile(Vector2f(64*1 + 64*5, 64*3), tileLightTexture64));
		break;
		case 1:
			temp.push_back(Tile(Vector2f(64*2, 64*3), tileDarkTexture64));

			temp.push_back(Tile(Vector2f(64*4 + 64*5, 64*3), tileLightTexture64));
		break;
		case 2:
			temp.push_back(Tile(Vector2f(32*1 + 32*10 + 16, 32*5), tileLightTexture32));
		break;
		case 3:
			temp.push_back(Tile(Vector2f(32*4, 32*7), tileDarkTexture64));
			temp.push_back(Tile(Vector2f(32*3, 32*5), tileDarkTexture32));
			temp.push_back(Tile(Vector2f(32*6, 32*3), tileDarkTexture32));

			temp.push_back(Tile(Vector2f(32*4 + 64*5, 32*2), tileLightTexture64));
			temp.push_back(Tile(Vector2f(32*3 + 32*10, 32*6), tileLightTexture32));
			temp.push_back(Tile(Vector2f(32*6 + 32*10, 32*9), tileLightTexture32));
		break;
		case 4:
			temp.push_back(Tile(Vector2f(32*3, 32*1), tileDarkTexture32));
			temp.push_back(Tile(Vector2f(32*1, 32*3), tileDarkTexture32));
			temp.push_back(Tile(Vector2f(32*5, 32*3), tileDarkTexture32));
			temp.push_back(Tile(Vector2f(32*3, 32*5), tileDarkTexture32));
			temp.push_back(Tile(Vector2f(32*7, 32*5), tileDarkTexture32));
			temp.push_back(Tile(Vector2f(32*7, 32*10), tileDarkTexture32));
			temp.push_back(Tile(Vector2f(32*3, 32*10), tileDarkTexture32));
			temp.push_back(Tile(Vector2f(32*5, 32*12), tileDarkTexture32));
			temp.push_back(Tile(Vector2f(32*7, 32*10), tileDarkTexture32));

			//temp.push_back(Tile(Vector2f(32*4, 32*7), tileDarkTexture64));
			temp.push_back(Tile(Vector2f(32*8, 32*7), tileDarkTexture64));

			temp.push_back(Tile(Vector2f(32*2 + 32*10, 32*2), tileLightTexture32));
			temp.push_back(Tile(Vector2f(32*5 + 32*10, 32*11), tileLightTexture32));

			temp.push_back(Tile(Vector2f(32*3 + 32*10, 32*1), tileLightTexture64));
			temp.push_back(Tile(Vector2f(32*8 + 32*10, 32*6), tileLightTexture64));
			temp.push_back(Tile(Vector2f(32*3 + 32*10, 32*11), tileLightTexture64));
		break;
	}
	return temp;
}

int level = 0;
std::vector<Tile> tiles = loadTiles(level);

bool gameRunning = true;
bool mouseDown = false;
bool mousePressed = false;

bool swingPlayed = false;
bool secondSwingPlayed = false;


SDL_Event event;

int state = 0; //0 = title screen, 1 = game, 2 = end screen

Uint64 currentTick = SDL_GetPerformanceCounter();
Uint64 lastTick = 0;
double deltaTime = 0;

void loadLevel(int level)
{
	if (level > 4)
	{
		state = 2;
		return;
	}
	balls[0].setVelocity(0, 0);
	balls[1].setVelocity(0,0);
    balls[0].setScale(1, 1);
	balls[1].setScale(1, 1);
	balls[0].setWin(false);
	balls[1].setWin(false);

	tiles = loadTiles(level);

	switch (level)
	{
		case 0:
			balls[0].setPos(24 + 32*4, 24 + 32*11);
			balls[1].setPos(24 + 32*4 + 32*10, 24 + 32*11);

			holes.at(0).setPos(24 + 32*4, 22 + 32*2);
			holes.at(1).setPos(24 + 32*4 + 32*10, 22 + 32*2);
		break;
		case 1:
			balls[0].setPos(24 + 32*4, 24 + 32*11);
			balls[1].setPos(24 + 32*4 + 32*10, 24 + 32*11);

			holes.at(0).setPos(24 + 32*4, 22 + 32*2);
			holes.at(1).setPos(24 + 32*4 + 32*10, 22 + 32*2);
		break;
		case 2:
			balls[0].setPos(8 + 32*7, 8 + 32*10);
			balls[1].setPos(8 + 32*7 + 32*10, 8 + 32*10);

			holes.at(0).setPos(8 + 32*2, 6 + 32*5);
			holes.at(1).setPos(8 + 32*4 + 32*10, 6 + 32*3);
		break;
		case 3:
			balls[0].setPos(24 + 32*4, 24 + 32*5);
			balls[1].setPos(24 + 32*4 + 32*10, 24 + 32*4);

			holes.at(0).setPos(24 + 32*4, 22 + 32*1);
			holes.at(1).setPos(24 + 32*4 + 32*10, 22 + 32*11);
		break;
		case 4:
			balls[0].setPos(24 + 32*2, 24 + 32*12);
			balls[1].setPos(24 + 32*0 + 32*10, 24 + 32*5);

			holes.at(0).setPos(24 + 32*1, 22 + 32*1);
			holes.at(1).setPos(24 + 32*0 + 32*10, 22 + 32*7);
		break;
	}
}

const char* getStrokeText()
{
	int biggestStroke = 0;
	if (balls[1].getStrokes() > balls[0].getStrokes())
	{
		biggestStroke = balls[1].getStrokes();
	}
	else
	{
		biggestStroke = balls[0].getStrokes();
	}
	std::string s = std::to_string(biggestStroke);
	s = "STROKES: " + s;
	return s.c_str();
}

const char* getLevelText(int side)
{
	int tempLevel = (level + 1)*2 - 1;
	if (side == 1)
	{
		tempLevel++;
	}
	std::string s = std::to_string(tempLevel);
	s = "HOLE: " + s;
	return s.c_str();
}

void update()
{

	lastTick = currentTick;
	currentTick = SDL_GetPerformanceCounter();
	deltaTime = (double)((currentTick - lastTick)*1000 / (double)SDL_GetPerformanceFrequency() );

	mousePressed = false;
	//Get our controls and events
	while (SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_QUIT:
			gameRunning = false;
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				mouseDown = true;
				mousePressed = true;
			}
			break;
		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				mouseDown = false;
			}
			break;
		}
	}

	if (state == 1)
	{
		for (Ball& b : balls)
		{
			b.update(deltaTime, mouseDown, mousePressed, tiles, holes, chargeSfx, swingSfx, holeSfx);
		}
		if (balls[0].getScale().x < -1 && balls[1].getScale().x < -1)
 		{
        	level++;
			loadLevel(level);
    	}
	}
}

void graphics()
{
	window.clear();
	window.render(0, 0, bgTexture);
	for (Hole& h : holes)
	{
		window.render(h);
	}
	for (Ball& b : balls)
	{
		if (!b.isWin())
		{
			window.render(b.getPos().x, b.getPos().y + 4, ballShadowTexture);
		}
		for (Entity& e : b.getPoints())
		{
			window.render(e);
		}
		window.render(b);
	}
	for (Tile& t : tiles)
	{
		window.render(t);
	}
	for (Ball& b : balls)
	{
		for (Entity& e : b.getPowerBar())
		{
			window.render(e);
		}
		window.render(b.getPowerBar().at(0).getPos().x, b.getPowerBar().at(0).getPos().y, powerMeterTexture_overlay);

	}
	if (state != 2)
	{
		window.render(640/4 - 132/2, 480 - 32, levelTextBgTexture);
		window.renderCenter(-160, 240 - 16 + 3, getLevelText(0), font24, black);
		window.renderCenter(-160, 240 - 16, getLevelText(0), font24, white);

		window.render(640/2 + 640/4 - 132/2, 480 - 32, levelTextBgTexture);
		window.renderCenter(160, 240 - 16 + 3, getLevelText(1), font24, black);
		window.renderCenter(160, 240 - 16, getLevelText(1), font24, white);

		window.render(640/2 - 196/2, 0, uiBgTexture);
		window.renderCenter(0, -240 + 16 + 3, getStrokeText(), font24, black);
		window.renderCenter(0, -240 + 16, getStrokeText(), font24, white);
	}
	else
	{
		window.render(0, 0, endscreenOverlayTexture);
		window.renderCenter(0, 3 - 32, "YOU COMPLETED THE COURSE!", font48, black);
		window.renderCenter(0, -32, "YOU COMPLETED THE COURSE!", font48, white);
		window.renderCenter(0, 3 + 32, getStrokeText(), font32, black);
		window.renderCenter(0, 32, getStrokeText(), font32, white);
	}
	window.display();
}

void titleScreen()
{
	if (SDL_GetTicks() < 2000)
	{
		if (!swingPlayed)
		{
			Mix_PlayChannel(-1, swingSfx, 0);
			swingPlayed = true;
		}
		//Get our controls and events
		while (SDL_PollEvent(&event))
		{
			switch(event.type)
			{
			case SDL_QUIT:
				gameRunning = false;
				break;
			}
		}

		window.clear();
		window.render(0, 0, bgTexture);
		window.render(0, 0, splashBgTexture);
		window.renderCenter(0, 0 + 3, "POLYMARS", font32, black);
		window.renderCenter(0, 0, "POLYMARS", font32, white);
		window.display();
	}
	else
	{
		if (!secondSwingPlayed)
		{
			Mix_PlayChannel(-1, swingSfx, 0);
			secondSwingPlayed = true;
		}
		lastTick = currentTick;
		currentTick = SDL_GetPerformanceCounter();
		deltaTime = (double)((currentTick - lastTick)*1000 / (double)SDL_GetPerformanceFrequency() );

		//Get our controls and events
		while (SDL_PollEvent(&event))
		{
			switch(event.type)
			{
			case SDL_QUIT:
				gameRunning = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					Mix_PlayChannel(-1, holeSfx, 0);
					state = 1;
				}
				break;
			}
		}
		window.clear();
		window.render(0, 0, bgTexture);
		window.render(320 - 160, 240 - 100 - 50 + 4*SDL_sin(SDL_GetTicks()*(3.14/1500)), logoTexture);
		window.render(0, 0, click2start);
		window.renderCenter(0, 240 - 48 + 3 - 16*5, "LEFT CLICK TO START", font32, black);
		window.renderCenter(0, 240 - 48 - 16*5, "LEFT CLICK TO START", font32, white);
		window.display();
	}
}
void game()
{
	if (state == 0)
	{
		titleScreen();
	}
	else
	{
		update();
		graphics();
	}
}
int main(int argc, char* args[])
{
	loadLevel(level);
	while (gameRunning)
	{
		game();
	}

	window.cleanUp();
	TTF_CloseFont(font32);
	TTF_CloseFont(font24);
	SDL_Quit();
	TTF_Quit();
	return 0;
}
