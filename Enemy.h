#pragma once

#ifndef ENEMY_F
#define ENEMY_F

#include <iostream>
#include <vector>
#include <SDL.h>

extern const int WIDTH;

class Enemy{
private:
	SDL_Rect EnBox;
	int posX, posY, VelocityX;
	std::string direction;
public:
	Enemy() {}
	void setDir(std::string dir);
	std::string getDir();
	void setWid(int w);
	void eventHandler();
	void setVelocity(int v);
	int getVelocity();
	void setPosX(int x);
	int getPosX();
	int setPosY(int y);
	SDL_Rect getBox();
};

#endif //ENEMY_F