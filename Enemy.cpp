#include <Enemy.h>

#include <iostream>
#include <vector>

//set direction
void Enemy::setDir(std::string dir) {
	direction = dir;
	if (direction == "l") {
		posX = WIDTH;
		EnBox.x = posX + 10;
	}
	else {
		posX = -220;
		EnBox.x = posX + 10;
	}
}

//set bounding box size for each type of enemy
void Enemy::setWid(int w) {
	EnBox.w = w / 10;
	EnBox.h = 25;
}

//handles movement
void Enemy::eventHandler() {
	if (direction == "l") {
		posX -= VelocityX;
		EnBox.x = posX + 10;
		//resets pos of object when it's out of the visible boundary
		if ((posX + 220) <= 0) {
			posX = WIDTH + 220;
			EnBox.x = posX + 10;
		}
	}
	else {
		posX += VelocityX;
		EnBox.x = posX + 10;
		//resets pos of object when it's out of the visible boundary
		if (posX >= WIDTH + 50) {
			posX = -220;
			EnBox.x = posX + 10;
		}
	}
}

//return velocity
int Enemy::getVelocity() {
	return VelocityX;
}

//set velocity
void Enemy::setVelocity(int v) {
	VelocityX = v;
}

//return the x coord
int Enemy::getPosX() {
	return posX;
}

//set x coord
void Enemy::setPosX(int x) {
	posX = x;
	EnBox.x = posX + 10;
}

//set y coord
int Enemy::setPosY(int y) {
	EnBox.y = y;
	return posY = y;
}

//return bounding box
SDL_Rect Enemy::getBox() {
	return EnBox;
}

//return direction
std::string Enemy::getDir() {
	return direction;
}