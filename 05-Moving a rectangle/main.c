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
	int b=255,a=0,c=0;
	int x=0,y=0;
	bool falling=true;
	while(running){
		//
		if(falling==true){
			x+=1;
			y+=1;
			
			if (x>200 && y>200){
			falling=false;
			a+=10;
			b=10;
			c+=20;

		}
		}
		//
		if(falling==false){
			x-=1;
			y-=1;
			if(x<0 && y<0){
				falling=true;
				a+=10;
				b=10;
				c+=20;
			}
		}
			
		
		if(SDL_PollEvent(&event)){
			if (event.type==SDL_QUIT){
				running=false;
			
			}
			 
			
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer,b, a, c, 255); 
		

		
		SDL_Rect rect = {x, y, 200, 200};
        	SDL_RenderFillRect(renderer, &rect);

       
        	SDL_RenderPresent(renderer);
	}
	
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}
 