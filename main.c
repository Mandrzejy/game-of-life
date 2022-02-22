#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctype.h>

#define PRINT_BLOCK printf("\033[0;37m\u2588\u2588")
#define PRINT_SPACE printf("\033[0;30m\u2588\u2588")
#define CLS printf("\033[H\033[J")
#define NEWLINE printf("\n")
#define index(x,y,row_size) (y)*(row_size)+x



int main(int argc, char** argv){
	if(argc==1){fprintf(stderr,"Filename not provided\n");return -1;}
	FILE* f=fopen(argv[1],"r");
	if(f==NULL){fprintf(stderr,"File couldn't be open\n");return -2;}
	int ROW_SIZE;
	int GEN;
	fscanf(f,"%d",&ROW_SIZE);	
	fscanf(f,"%d",&GEN);
	int* grid = calloc((ROW_SIZE)*(ROW_SIZE),sizeof(int));	
	int* next = calloc((ROW_SIZE)*(ROW_SIZE),sizeof(int));
	if(grid==NULL || next==NULL){fprintf(stderr,"Memory error\n");return -3; }
	char c;
	for(int y=0;y<ROW_SIZE;y++){
		for(int x=0;x<ROW_SIZE;x++){
			c=getc(f);
			while(c=='\n' || c==' '){c=getc(f);}
			grid[index(x,y,ROW_SIZE)]=(c=='0'?0:1);
			
		}
	}
	fclose(f);	
	while((GEN>0)){

		for(int y=0;y<ROW_SIZE;y++){
			for(int x=0;x<ROW_SIZE;x++){
				int s=0;
				for(int dy=-1;dy<2;dy++){
					for(int dx=-1;dx<2;dx++){
						if(dx==dy && dx==0){continue;}
						int new_x=(ROW_SIZE+x+dx)%ROW_SIZE;	
						int new_y=(ROW_SIZE+y+dy)%ROW_SIZE;
						s+=grid[index(new_x,new_y,ROW_SIZE)];
					}

				}		
				if(s==3){next[index(x,y,ROW_SIZE)]=1;}
				else if(s==2 && grid[index(x,y,ROW_SIZE)]){next[index(x,y,ROW_SIZE)]=1;}
			}
		
		}

		
		for(int y=0;y<ROW_SIZE;y++){
			for(int x=0;x<ROW_SIZE;x++){
				grid[index(x,y,ROW_SIZE)]=next[index(x,y,ROW_SIZE)];
				next[index(x,y,ROW_SIZE)]=0;
			}
		}

		
		for(int y=0;y<ROW_SIZE;y++){
			for(int x=0;x<ROW_SIZE;x++){
				grid[index(x,y,ROW_SIZE)]?PRINT_BLOCK:PRINT_SPACE;
			}
			NEWLINE;
		}
		
		usleep(50000);
		GEN--;
		if(GEN!=0){CLS;}
	}



}
