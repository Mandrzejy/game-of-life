#include<stdio.h>
#include<stdlib.h>
#define WIDTH 30
#define HEIGHT 40

#define PRINT_BLOCK printf("\033[0;37m\u2588\u2588")
#define PRINT_SPACE printf("\033[0;30m\u2588\u2588");
#define CLS printf("\033[H\033[J")


void copy(int what[WIDTH+2][HEIGHT+2],int where[WIDTH+2][HEIGHT+2]){
	for(int y=0;y<HEIGHT+2;y++){
		for(int x=0;x<WIDTH+2;x++){
			where[y][x]=what[y][x];
	
		}
	}
	
}
int grid[WIDTH+2][HEIGHT+2];
int _next_gen[WIDTH+2][HEIGHT+2];
void print_grid(){
	CLS;	
	for(int y=1;y<HEIGHT+1;y++){
		for(int x=1;x<WIDTH+1;x++){
			grid[y][x]==1?PRINT_BLOCK:PRINT_SPACE;
		}
		printf("\n");
	}
}


void next_gen(){
	for(int y=1;y<HEIGHT+1;y++){
		for(int x=1;x<WIDTH+1;x++){
			//where
			int n=grid[y][x-1]+grid[y][x+1]+ \
			      grid[y-1][x]+grid[y-1][x-1]+grid[y-1][x+1]+\
			      grid[y+1][x]+grid[y+1][x-1]+grid[y+1][x+1];


				if(n==3 || n==2){
					if(grid[y][x]==0){if(n==3){_next_gen[y][x]=1;}else{_next_gen[y][x]=0;}}
					else{_next_gen[y][x]=1;}

				}
				else{
					_next_gen[y][x]=0;
				}
		}


	}
	copy(_next_gen,grid);
}

int main(){	
	
	grid[10][3]=1;
	grid[10][4]=1;
	grid[10][5]=1;
	grid[12][4]=1;
	

	
	char c;
	while(1){
		print_grid();
		next_gen();
		while((c=getchar())!='\n'){if(c=='q'){exit(0);}};	
	}



}
