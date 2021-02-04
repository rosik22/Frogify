#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <map>

class Texture {
private:
	Texture() {}
	static Texture* texture;
	std::map<std::string, SDL_Texture*> texMap;

public:
	static Texture* getTexture() {
		texture = (texture == NULL) ? new Texture() : texture;
		return texture;
	}
	bool Load(std::string id, std::string fname);
	void Drop(std::string id);
	void Draw(std::string id, int x, int y, int width, int height, SDL_Rect dRec, std::string type);
	void Clear();
};

#endif // !TEXTURE_H
