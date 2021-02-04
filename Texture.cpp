#include <Texture.h>
#include <iostream>
#include <Engine.h>

Texture* Texture::texture = nullptr;

bool Texture::Load(std::string id, std::string fname) {
	SDL_Surface* textureSurface = IMG_Load(fname.c_str());
	if (textureSurface == NULL) {
		std::cout << "Could not load texture" << SDL_GetError() << std::endl;
		return false;
	}

	SDL_Texture* tex = SDL_CreateTextureFromSurface(Engine::getEngine()->getRenderer(), textureSurface);
	if (tex == NULL) {
		std::cout << "Could not create texture from surface " << SDL_GetError() << std::endl;
		return false;
	}

	texMap[id] = tex;
	return true;
}
void Texture::Drop(std::string id) {
	SDL_DestroyTexture(texMap[id]);
	texMap.erase(id);
}
void Texture::Draw(std::string id, int x, int y, int width, int height, SDL_Rect dRec, std::string type) {
	SDL_Rect sRec = { 0, 0, width, height };
	if(type == "none")
		SDL_RenderCopyEx(Engine::getEngine()->getRenderer(), texMap[id], &sRec, &dRec, 0, NULL, SDL_FLIP_NONE);
	else
		SDL_RenderCopyEx(Engine::getEngine()->getRenderer(), texMap[id], &sRec, &dRec, 0, NULL, SDL_FLIP_HORIZONTAL);
}

void Texture::Clear() {
	std::map<std::string, SDL_Texture*>::iterator it;
	for (it = texMap.begin(); it != texMap.end(); it++) {
		SDL_DestroyTexture(it->second);
	}
	texMap.clear();
}