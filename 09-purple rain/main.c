#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdlib.h>
int printRandoms(int lower, int upper );
void screen();
int rain(int y);
int x=0,y=0,width_rect=2,height_rect=10;
int y_pos=5;
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
	printf("%d",x);

	y=printRandoms(-100,100);
	int coor_x[200];
	for(int i=0;i<200;i++){
		coor_x[i]=printRandoms(0,400);
	}
	int coor_y[200];
	for(int i=0;i<200;i++){
		coor_y[i]=printRandoms(-100,300);
	}
	while(running){
		if(SDL_PollEvent(&event)){
			if (event.type==SDL_QUIT){
				running=false;
			}
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

		SDL_RenderClear(renderer);
		
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); 
		for(int i=0;i<200;i++){

			SDL_Rect rect = {coor_x[i], coor_y[i], width_rect, height_rect};
			SDL_RenderFillRect(renderer, &rect);

			coor_y[i]+=printRandoms(1,3);
			if(coor_y[i]>400){
				coor_y[i]=-10;
			}
			 
		}

		


       
        	SDL_RenderPresent(renderer);
	}
	
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}
int rain(int y) {
	return 5+y;
}
int printRandoms(int lower, int upper )
{
    int i;
        int num = (rand() % (upper - lower + 1)) + lower;
}