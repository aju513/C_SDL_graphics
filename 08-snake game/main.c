#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdlib.h>
void screen();
 
int Randoms(int lower,int upper);
int main(int argc, char* argv[]){
	SDL_Init(SDL_INIT_VIDEO);
	screen();
	SDL_QUIT;
	return 0;
}
int x=0,y=0;
int Randoms(int lower, int upper)
                             
{
    	int i;
    
	int num = (rand() %
	(upper - lower + 1)) + lower;
     
   	return num;
}
 
void screen(){

	SDL_Window *window;
	window=SDL_CreateWindow("hello",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,400,400,SDL_WINDOW_OPENGL);
	bool running=true;
	SDL_Event event;
	Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	SDL_Renderer *renderer = SDL_CreateRenderer(window,-1,render_flags);
	SDL_SetRenderDrawColor(renderer,0,0,255,0);
	int x_pos=0;
	int y_pos=0; 
	int x=0,y=0;
	int length=3;
	int speed=2;		
	int randomx=Randoms(0,300);
	int randomy=Randoms(0,300);
	int coorx[500];
	int coory[500];
	 
	int counter=0;
	while(running){
		
		if(SDL_PollEvent(&event)){
			if (event.type==SDL_QUIT){
				running=false;
			}
			if (event.type==SDL_KEYDOWN){
				
				
				if(event.key.keysym.scancode==SDL_SCANCODE_UP){
					y_pos=-speed;
					x_pos=0;
					 
				}
				if(event.key.keysym.scancode==SDL_SCANCODE_DOWN){
					y_pos=speed;
					x_pos=0;
				}
				if(event.key.keysym.scancode==SDL_SCANCODE_RIGHT){
					x_pos=speed;
					y_pos=0;
				}
				if(event.key.keysym.scancode==SDL_SCANCODE_LEFT){
					x_pos=-speed;
					y_pos=0;

				}

			}
		}
		
		
				 
		
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

		SDL_RenderClear(renderer);
		
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); 

		x+=x_pos;
		y+=y_pos;
	 
	 
 
		coorx[length-1]=x;
		coory[length-1]=y;
		

		 

		SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); 
		
		for(int i=0;i<length-1;i++)	 {
			coorx[i]=coorx[i+1];
			coory[i]=coory[i+1];
			SDL_Rect rect2 = {coorx[i+1], coory[i+1],10,10};
			
			SDL_RenderFillRect(renderer, &rect2);
			 
		}
		for(int i=0;i<length-2;i++){

			int distance2=(((coorx[length-1]-coorx[i])*(coorx[length-1]-coorx[i]))+((coory[length-1]-coory[i])*(coory[length-1]-coory[i])))*(0.5);
			if (distance2==0)
			{
				length=2;
				printf("%d\n",distance2);
			}
		}
		
		 
		int distance=(((randomx-x)*(randomx-x))+((randomy-y)*(randomy-y)))*(0.5);
		 
		if(distance<=12)	{
			randomx = Randoms(0,300);
			randomy = Randoms(0,300);
		 	speed+=0.1;
			length+=5;
			 
			
		}
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		SDL_Rect rect3 = {randomx, randomy,10,10};
			
		SDL_RenderFillRect(renderer, &rect3);	
		 
		if(x<0){
			x=0;
		}
		if(x>390){
			x=390;
		}
		if(y>300){
			y=300;
		}
		if(y<0){
			y=0;
		}
		
		
	 
       
        	SDL_RenderPresent(renderer);
		
		 
	}
	
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}
 