#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

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
	SDL_SetRenderDrawColor(renderer,0,0,255,0);
	while(running){
		if(SDL_PollEvent(&event)){
			if (event.type==SDL_QUIT){
				running=false;
			}
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); 
		

		
		SDL_Rect rect = {50, 50, 200, 200};
        	SDL_RenderFillRect(renderer, &rect);
		
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Red color
		SDL_Rect rect2 = {250, 300, 200, 250};
		SDL_RenderDrawRect(renderer, &rect2);


       
        	SDL_RenderPresent(renderer);
	}
	
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}
 