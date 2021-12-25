#include<stdio.h>
#include<stdlib.h>
#define WIDTH 75
#define HEIGHT 40

#define PRINT_BLOCK printf("\033[0;37m\u2588\u2588")
#define PRINT_SPACE printf("\033[0;30m\u2588\u2588");
#define CLS printf("\033[H\033[J")
#define NEWLINE printf("\n")
#define ROW_SIZE WIDTH+2

#define index(x,y,row_size) (y)*(row_size)+x
int grid[(HEIGHT+2)*(WIDTH+2)];

int next[(HEIGHT+2)*(WIDTH+2)];


void copy(){
	for(int y=1;y<HEIGHT+1;y++){
		for(int x=1;x<WIDTH+1;x++){
			grid[index(x,y,WIDTH+2)]=next[index(x,y,WIDTH+2)];
		}
	}
}


void print_grid(){
	CLS;
	for(int y=1;y<HEIGHT+1;y++){
		for(int x=1;x<WIDTH+1;x++){
			grid[index(x,y,WIDTH+2)]?PRINT_BLOCK:PRINT_SPACE;	
		}
		NEWLINE;
	}
}
void compute_next(){
	for(int y=1;y<HEIGHT+1;y++){
		for(int x=1;x<WIDTH+1;x++){
			int n=0;
			n= grid[index(x-1,y,ROW_SIZE)]+grid[index(x+1,y,ROW_SIZE)] \
			     + grid[index(x-1,y-1,ROW_SIZE)]+grid[index(x,y-1,ROW_SIZE)]+grid[index(x+1,y-1,ROW_SIZE)] \
			     + grid[index(x-1,y+1,ROW_SIZE)]+grid[index(x,y+1,ROW_SIZE)]+grid[index(x+1,y+1,ROW_SIZE)];
			
			if(n==3 || n==2){
				if(grid[index(x,y,ROW_SIZE)]==0){if(n==3){next[index(x,y,ROW_SIZE)]=1;}else{next[index(x,y,ROW_SIZE)]=0;}}
				else{next[index(x,y,ROW_SIZE)]=1;}
			}
			else{
				next[index(x,y,ROW_SIZE)]=0;
			}		

		}


	}
	copy();

}

int main(){	
	#if 0	
	grid[index(3,10,WIDTH+2)]=1;
	grid[index(4,10,WIDTH+2)]=1;
	grid[index(5,10,WIDTH+2)]=1;
	grid[index(4,12,WIDTH+2)]=1;
	#endif
	#if 1
	grid[index(5,5,ROW_SIZE)]=1;
	grid[index(6,6,ROW_SIZE)]=1;
	grid[index(7,6,ROW_SIZE)]=1;
	grid[index(7,5,ROW_SIZE)]=1;
	grid[index(7,4,ROW_SIZE)]=1;
	#endif
	#if 0
	srand(112137829);
	for(int y=1;y<HEIGHT+1;y++){
		for(int x=1;x<WIDTH+1;x++){
			grid[index(x,y,ROW_SIZE)]=rand()%2;
		}
	}


	#endif
	
	char c;
	while(1){
		print_grid();
		compute_next();
		
		while((c=getchar())!='\n'){if(c=='q'){exit(0);}};	
	}



}
