#include <stdio.h>
 
int gen[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int ruleset[]={0,0,0,1,1,1,1,0};
int size = sizeof gen / sizeof gen[0];
int alive=1;
int dead=0;
 
int rules(int a, int b, int c){
    if(a==alive && b==alive && c==alive){return ruleset[0];}
    if(a==alive && b==alive && c==dead){return ruleset[1];}
    if(a==alive && b==dead && c==alive){return ruleset[2];}
    if(a==alive && b==dead && c==dead){return ruleset[3];}
    if(a==dead && b==alive && c==alive){return ruleset[4];}
    if(a==dead && b==alive && c==dead){return ruleset[5];}
    if(a==dead && b==dead && c==alive){return ruleset[6];}
    if(a==dead && b==dead && c==dead){return ruleset[7];}
}
 
int get_gen(int pos,int *gen,int sz){
    if(pos<0 || pos>=sz){
        return 0;
    }
    return gen[pos];
}
 
int main(void){
    int iterations;
    int procces;
    for(iterations=0;iterations<30;iterations++){
    	int left=get_gen(-1,gen,size);
        for(procces=0;procces<size;procces++){
            int right=get_gen(procces+1,gen,size);
            int cell=get_gen(procces,gen,size);
 
            gen[procces]=rules(left,cell,right);
            if(gen[procces]==0){
                printf(" ");
            } else {
                printf("@");
            }
            left=cell;
        }
        printf("\n");
    }
}


int ruleset(int grid[sizeX][sizeY], int x, int y){
 if(grid[x-1][y+1]==0 && grid[x][y+1]==0 && grid[x+1][y+1]==0){
  grid[x][y] = 0;
  grid[x][y+1] = 1;
	}
	else if(grid[x][y+1]==1){
		if(grid[x-1][y+1]==0){
		 grid[x][y] = 0;
		 grid[x-1][y+1] = 1;
	 }
	 else if(grid[x+1][y+1]== 0){
	 	grid[x][y] = 0;
	 	grid[x+1][y+1] = 1;
	 }
	}
}
