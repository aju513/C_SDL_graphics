#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdlib.h>
int printRandoms(int lower,int upper);
void screen();
int main(int argc, char* argv[]){
	SDL_Init(SDL_INIT_VIDEO);
	screen();
	SDL_QUIT;
	return 0;
}
int printRandoms(int lower, int upper )
{
    int i;
        int num = (rand() % (upper - lower + 1)) + lower;
}
void screen(){

	SDL_Window *window;
	window=SDL_CreateWindow("hello",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,800,400,SDL_WINDOW_OPENGL);
	bool running=true;
	SDL_Event event;
	Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	SDL_Renderer *renderer = SDL_CreateRenderer(window,-1,render_flags);
	SDL_SetRenderDrawColor(renderer,0,0,255,0);
	int temp;
	int length=160;
	int height[length];
	int width[length];
	int x[length];
	x[0]=0;
	
	int r[length],g[length],b[length];
	for(int i=0;i<length-1;i++){
		height[i]=printRandoms(-400,0);
		 
		x[i+1]=x[i]+5;
		r[i]=printRandoms(0,255);
		b[i]=printRandoms(0,255);
		g[i]=printRandoms(0,255);
		
	}
	 

	while(running){
		if(SDL_PollEvent(&event)){
			if (event.type==SDL_QUIT){
				running=false;
			}
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

		SDL_RenderClear(renderer);
		
		for(int i=0;i<length-1;i++){
			
			SDL_SetRenderDrawColor(renderer, r[i], g[i], b[i], 255); 
			
			SDL_Rect rect = {x[i], 400, 5, height[i]};
			SDL_RenderFillRect(renderer, &rect);
			if(height[i]<height[i+1]){
			 
				temp=height[i];

				height[i]=height[i+1];
				height[i+1]=temp;
			 
			}
			 

		}
		SDL_Delay(10);
		
        	SDL_RenderPresent(renderer);
		
	}
	
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}
 