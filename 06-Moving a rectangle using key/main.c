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
	int x=0,y=0;
	while(running){
		if(SDL_PollEvent(&event)){
			if (event.type==SDL_QUIT){
				running=false;
			}
			if (event.type==SDL_KEYDOWN){
				if(event.key.keysym.scancode==SDL_SCANCODE_UP){
					y-=3;
					if(y<0){
						y=0;
					}
				}
				if(event.key.keysym.scancode==SDL_SCANCODE_DOWN){
					y+=3;
					if(y>200){
					y=200;
					}
				}
				if(event.key.keysym.scancode==SDL_SCANCODE_RIGHT){
					x+=3;

					if(x>200){
						x=200;
					}
				}
				if(event.key.keysym.scancode==SDL_SCANCODE_LEFT){
					x-=3;

					if(x<0){
						x=0;
					}
				}
			}
			
			
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); 
		

		SDL_Rect rect = {x, y, 200, 200};
        	SDL_RenderFillRect(renderer, &rect);
		


       
        	SDL_RenderPresent(renderer);
	}
	
	
	
}
 