#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <SDL2/SDL_image.h>
void screen();
int main(int argc, char* argv[]){
	SDL_Init(SDL_INIT_VIDEO);
	screen();
	SDL_QUIT;
	return 0;
}
void screen(){

	SDL_Window *window;
	window=SDL_CreateWindow("hello",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,400,400,SDL_WINDOW_OPENGL);
	bool running=true;
	SDL_Event event;
	Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	SDL_Renderer *renderer = SDL_CreateRenderer(window,-1,render_flags);
	SDL_Surface* surface = IMG_Load("./hello.png");
	SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	while(running){
		if(SDL_PollEvent(&event)){
			if (event.type==SDL_QUIT){
				running=false;
			}
		}
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, tex, NULL, NULL);
       
        	SDL_RenderPresent(renderer);
	}
	
	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}
 