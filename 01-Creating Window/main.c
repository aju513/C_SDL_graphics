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
	while(running){
		 
		if(SDL_PollEvent(&event)){
			 
			if (event.type==SDL_QUIT){
				running=false;
			}
		}
	}
	SDL_DestroyWindow(window);
}