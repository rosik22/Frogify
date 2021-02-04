#include <Frog.h>

#include <SDL.h>
#include <iostream>
#include <vector>

Frog* Frog::frog = nullptr;

//initial position
void Frog::begin() {
	posY = 576;
	posX = 290;
	FBox.x = posX + 10;
	FBox.y = posY;
	FBox.w = 32;
	FBox.h = FHeight;
}

//handles frog movement
void Frog::eventHandler(SDL_Event& event)
{
	if (event.type == SDL_KEYDOWN && (event.key.keysym.sym == SDLK_w || event.key.keysym.sym == SDLK_s || event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_d)) {
		++frame;
		switch (event.key.keysym.sym) {
		case SDLK_w:
			//checks whether frog is below highest point of the map
			if (posY >= FHeight - 28) {
				//adjust x coord when the frog is on a log
				if (posY < 356) {
					int adjust = posX - (posX % 64) + 30;
					posX = adjust;
					FBox.x = posX + 10;
				}
				//stops movement if there is a grass area ahead
				if (posY == 48 && (posX == 606 || posX == 478 || posX == 350 || posX == 222 || posX == 94 || posX == -34)) break;
				//stops movement if there is a safe zone that's already checked
				if (posY == 48 && std::find(safeZone.begin(), safeZone.end(), posX) != safeZone.end()) break;
				posY -= FHeight - 20;
				FBox.y = posY;
				//checks whether points should be given
				if (posY < highest) {
					highest = posY;
					Score += 10;
					//checks if a safe zone is reached
					if (posY == 4) {
						safeZone.push_back(posX);
						Score += 50;
					}
				}
			}
			break;

		case SDLK_s:
			if (posY < 356) {
				//adjust x coord
				int adjust = posX - (posX % 64) + 30;
				posX = adjust;
				FBox.x = posX + 10;
			}
			//restricts from going bellow the map
			if (posY < 640 - FHeight) {
				posY += FHeight - 20;
				FBox.y = posY;
			}
			break;

		case SDLK_a:
			if (posX > 0) {
				if (posY == 4 && (posX == 674 || posX == 546 || posX == 418 || posX == 290 || posX == 162 || posX == 34)) break;
				posX -= FWidth;
				FBox.x = posX + 10;
			}
			break;

		case SDLK_d:
			if (posX < 640 - FWidth) {
				if (posY == 4 && (posX == 674 || posX == 546 || posX == 418 || posX == 290 || posX == 162 || posX == 34)) break;
				posX += FWidth;
				FBox.x = posX + 10;
			}
			break;
		}

	}
}

//return Frog's bounding box
SDL_Rect Frog::getBox() {
	return FBox;
}

//return score
int Frog::getScore() {
	return Score;
}

//set the highest position
void Frog::setHighest() {
	highest = 640;
}

//return vector holding the reached safe zones
std::vector<int> Frog::getSafe() {
	return safeZone;
}

//set the x coord
void Frog::setPosX(int num) {
	posX += num;
	FBox.x += num;
}

//return x coord
int Frog::getPosX() {
	return posX;
}

//return y coord
int Frog::getPosY() {
	return posY;
}

//return frame
int Frog::getFrame() {
	return frame;
}

//reset in-game score
void Frog::resetScore() {
	Score = 0;
}

//empty vector after game restart
void Frog::clearZone() {
	safeZone.clear();
}