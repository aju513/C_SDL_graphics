#include <stdio.h>
 
#include <SDL2/SDL.h>
#include <stdbool.h>
 
int a=0,b=255,c=0;
int x1=0,y1=0;
int x2=370,y2=0;
int x3=200,y3=200;	
	
 
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
	

	//declaring movement x,y
	
	int ball_movement_x=3;
	int ball_movement_y=3;	
	int distance1,distance2;
	
	
	while(running){
		if(SDL_PollEvent(&event)){
			if (event.type==SDL_QUIT){
				running=false;
			}
		}
		//keydown
		if (event.type==SDL_KEYDOWN){
			//up
			if(event.key.keysym.scancode==SDL_SCANCODE_UP){
				y2-=5;
				if(y2<0){
					y2=0;

				}
			}
			//down
			if(event.key.keysym.scancode==SDL_SCANCODE_DOWN){
				y2+=5;
				if(y2>300){
					y2=300;
				}

			}
			//s
			if(event.key.keysym.scancode==SDL_SCANCODE_S){
				y1+=9;	
				if(y1>300){
					y1=300;
				}


			}
			//w
			if(event.key.keysym.scancode==SDL_SCANCODE_W){
				y1-=9;
				if(y1<0){
					y1=0;
				}

			}
			
			
		}
		//ball movement
		if(x3<x1+30 && y3<y1+100 && y3>y1){
			ball_movement_x=4;

		}

		//crash with rect2
		 if(x3>x2-30 && y3<y2+100 && y3>y2){
			ball_movement_x=-4;
			printf("yes");
			printf("%d",y2-100);
			

		}

			 
			 
			 
		 
		
		//crash bottom
		if(y3>=370){
			ball_movement_y=-4;
		}
		//crash top
		if(y3<=0){
			ball_movement_y=+4;
		}		
		//crash right
		if(x3>=370){
			ball_movement_x=-4;
		}
		//crash left
		if(x3<=0){
			ball_movement_x=+4;
		}

		//crash with rect1
		

		
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		//changescreen
		SDL_SetRenderDrawColor(renderer, 255, 0,0, 255); 
		

		//RECTANGLE1
		SDL_Rect rect1 = {x1, y1, 30, 100};
        	SDL_RenderFillRect(renderer, &rect1);
		//RECTANGLE2
		SDL_Rect rect2 = {x2, y2, 30, 100};
        	SDL_RenderFillRect(renderer, &rect2);
		//BOX
		SDL_SetRenderDrawColor(renderer, a, b,c, 255); 
		SDL_Rect rect3 = {x3, y3, 30, 30};
        	SDL_RenderFillRect(renderer, &rect3);
		//presentrenderer	
        	SDL_RenderPresent(renderer);
		
		x3+=ball_movement_x;
		y3+=ball_movement_y;
	 


	}
	
	
	
}
