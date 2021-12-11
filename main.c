#include<stdio.h>
#include<stdbool.h>
#define WIDTH 20
#define HEIGHT 20

#define PRINT_BLOCK printf("\033[0;37m\u2588\u2588")
#define PRINT_SPACE printf("\033[0;30m\u2588\u2588");



void copy(bool what[20][20],bool where[20][20]){}
bool grid[WIDTH][HEIGHT];
bool _next_gen[WIDTH][HEIGHT];
bool ptr[WIDTH][HEIGHT];
void print_grid(){	
	for(int y=0;y<HEIGHT;y++){
		for(int x=0;x<WIDTH;x++){
			grid[y][x]==1?PRINT_BLOCK:PRINT_SPACE;
		}
		printf("\n");
	}
}

void next_gen(){
	for(int y=0;y<HEIGHT;y++){
		for(int x=0;x<WIDTH;x++){
			int neighbors=0;
			if(y==0){
				if(x==0){
					neighbors=grid[1][1]+grid[0][1]+grid[1][0];
				}
				if(x==WIDTH-1){
					neighbors=grid[0][WIDTH-2]+grid[1][WIDTH-1]+grid[1][WIDTH-2];
				}
				else{

					neighbors=grid[y][x-1]+grid[y+1][x]+grid[y+1][x-1]+grid[y+1][x+1]+grid[y][x+1];
				}				
			}
			else if(x==0){
					
			}
			else if(y==HEIGHT-1){

			}
			else if(x==WIDTH -1){

			}
			else{

			}
			//neighbors 	
		}


	}	
	copy(_next_gen,grid);
}

int main(){
	grid[2][4]=1;
	grid[2][3]=1;
	grid[3][4]=1;
	grid[3][7]=1;
	next_gen();
	print_grid();




}
