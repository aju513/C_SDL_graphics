#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <math.h>
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
	float value;
	float result;
	float p=0,h=5;
	 
	float x[10000];
	float y[10000];
	float length[10000];
	int counter=0;
	length[counter]=20;
	while(running){
		if(SDL_PollEvent(&event)){
			if (event.type==SDL_QUIT){
				running=false;
			}
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

		SDL_RenderClear(renderer);
		
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); 
	
		value=p/h;
		result=sin(value);
		x[counter]=value;
		y[counter]=result;
		for(int i=0;i<counter-1;i++){

			SDL_RenderDrawPoint(renderer, x[i]*4, y[i]*4+length[i]);
		}
		p+=1;
       
        	SDL_RenderPresent(renderer);
		counter+=1;
		if (value>100){
			p=0;
			length[counter]=length[counter-3]+20;
		}
		length[counter+1]=length[counter];
	}
	
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}
 