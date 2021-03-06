#ifndef sdl_renderer_h
#define sdl_renderer_h

// CPP
#include <vector>
#include <string>

// SDL2
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

// LOCAL
#include "renderer.h"

class SDLRenderer : public Renderer
{
public:
	SDLRenderer();
	~SDLRenderer();
	
	void Init();
	void Clear();
	void Present();
	void GetSceneSize(int& width, int& height);
	void Render(const TRex::Object& obj, const GameShape* src,
              const GameShape* dest);
	void Render(const TRex::Object& obj, const int x, const int y,
              const int w = 0, const int h = 0);
	
private:
 	void DestroyTextures(); 
	SDL_Texture* LoadTexture(std::string file);
	
	SDL_Window* window_;
	SDL_Renderer* renderer_;
	std::vector<SDL_Texture*> textures_;
	std::vector<SDL_Rect> texture_sizes_; 
};

#endif /* sdl_renderer_h */
