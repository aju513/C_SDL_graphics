#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <SDL2/SDL_image.h>
#include <stdlib.h>
void screen();
int Randoms(int lower, int upper);
int main(int argc, char* argv[]){
	SDL_Init(SDL_INIT_VIDEO);
	screen();
	SDL_QUIT;
	return 0;
}
int Randoms(int lower, int upper)
                             
{
    	int i;
    
	int num = (rand() %
	(upper - lower + 1)) + lower;
     
   	return num;
}
void screen(){
	SDL_Window *window;
	 IMG_Init(IMG_INIT_PNG);
	window=SDL_CreateWindow("hello",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,400,400,SDL_WINDOW_OPENGL);
	bool running=true;
	//event initialization
	SDL_Event event;
	SDL_Texture * texture;
	//some graphics thing
	Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	//just creating render
	SDL_Renderer *renderer = SDL_CreateRenderer(window,-1,render_flags);
	//copying the pixelfrom the image
	SDL_Surface* surface = IMG_Load("./bird3.png");
	//creating a texture in render
	Uint32 colorkey = SDL_MapRGB(surface->format, 247, 247, 247);
	SDL_SetColorKey(surface, SDL_TRUE, colorkey);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surface);
	int height1=Randoms(0,200);
	int height2=Randoms(0,200);
	SDL_FreeSurface(surface);
	int x=50,y=40;
	double gravity=1;
	int x1=30;
	int y1=200;
	int xUp=400;
	while(running){
		if(SDL_PollEvent(&event)){
			if (event.type==SDL_QUIT){
				running=false;

			}
			if(event.key.keysym.scancode==SDL_SCANCODE_SPACE){
				y1-=15;
				 
			}
		}
		 
                SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
		
		
		 
               
		SDL_RenderClear(renderer);
	
		//image-flappybird 
		SDL_Rect rect = {x1, y1, x, y};
		SDL_RenderCopy(renderer, tex, NULL, &rect); 

		//rectangle
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		SDL_Rect rect1 = {xUp, 0, 50,height1};
		SDL_RenderFillRect(renderer, &rect1);	
        	
		//rectangle
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		SDL_Rect rect2 = {xUp, 400-height2, 50,height2};
		SDL_RenderFillRect(renderer, &rect2);	
		SDL_RenderPresent(renderer);
		y1+=gravity;
		xUp-=5;
		if(y1<=height1 && xUp==x1){
			running=false;

		}
		if(y1>=400-height2 && xUp==x1){
			running=false;
		}
		if(xUp<0){
			xUp=500;
			height1=Randoms(100,200);
			height2=Randoms(0,200); ;
		}
		
	}
		
	 
		
	
	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

		
	
}
 