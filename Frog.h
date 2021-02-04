#ifndef FROG_H
#define FROG_H

#include <vector>
#include <SDL.h>
#include <Enemy.h>
#include <vector>

class Frog
{
private:
	Frog() {}
	static Frog* frog;
	SDL_Rect FBox;
	int FWidth = 64, FHeight = 64;
	int posY = 576;
	int posX = 290;
	int Score = 0;
	int highest = 640;
	int frame = 0;
	std::vector<int> safeZone;

public:
	//Initialization
	static Frog* getFrog() {
		frog = (frog == NULL) ? new Frog() : frog;
		return frog;
	}

	void begin();
	void eventHandler(SDL_Event& event);
	SDL_Rect getBox();
	int getScore();
	void setHighest();
	std::vector<int> getSafe();
	void setPosX(int num);
	int getPosX();
	int getPosY();
	int getFrame();
	void resetScore();
	void clearZone();
};

#endif