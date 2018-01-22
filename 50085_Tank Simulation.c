#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
 
int n, m;
bool wall(int x, int y){
    if(x<0 || x>=m || y<0 || y>=n)
        return true;
    else
        return false;
}
 
int main(void){
    scanf("%d%d", &n, &m);
 
    short map[n+1][m+1];
    memset(map, 0, sizeof(map));
 
    int tLen, tHei;
    scanf("%d%d", &tLen, &tHei);
    for(int i = 0;i < tLen;i++)
        for(int j = 0;j < tHei;j++)
            map[i][j] = 1;
 
    int obC;
    scanf("%d", &obC);
    while(obC--){
        int obX, obY;
        scanf("%d%d", &obX, &obY);
 
        map[obY][obX] = 2;
    }
 
    int cmd;
    int initY = 0, initX = 0;
    while( scanf("%d", &cmd) == 1 ){
        if(cmd == 0)
            for(int i = 0;i < n;i++){
                for(int j = 0;j < m;j++)
                    printf("%hi", map[i][j]);
 
                printf("\n");
            }
            //printf("-------\n");
 
        else{
        	short onO = 0, bump = 0;
            int dx = 0, dy = 0;
            
            switch(cmd){
                case 1:
                    for(int i = 0;i < tLen;i++){
	                    if( wall(initX+tHei, initY+i) ){
	                        bump = 1;
	                        break;
	                    }
	                    if( map[initY+i][initX+tHei] == 2)
	                        onO++;
                	}
                	
                	dx = 1;
                    break;
                case 2:
                    for(int i = 0;i < tHei;i++){
	                    if( wall(initX+i, initY+tLen) ){
	                        bump = 1;
	                        break;
	                    }
	                    if( map[initY+tLen][initX+i] == 2)
	                        onO++;
                    } 
                    
                    dy = 1;
                    break;
                case 3:
                    for(int i = 0;i < tLen;i++){
	                    if( wall(initX-1, initY+i) ){
	                        bump = 1;
	                        break;
	                    }
	                    if( map[initY+i][initX-1] == 2)
	                        onO++;
	                }
	                
	                dx = -1;
                    break;
                case 4:
                    for(int i = 0;i < tHei;i++){
	                    if( wall(initX+i, initY-1) ){
	                        bump = 1;
	                        break;
	                    }
	                    if( map[initY-1][initX+i] == 2)
	                        onO++;
	                }
	                
	                dy = -1;
                    break;
                case 5:
                    for(int i = 0;i < tLen-1;i++){
	                    if( wall(initX+tHei, initY+1+i) ){
	                        bump = 1;
	                        break;
	                    }
	                    if( map[initY+1+i][initX+tHei] == 2)
	                        onO++;
	                }
					
					for(int i = 0;i < tHei;i++){
	                    if( wall(initX+1+i, initY+tLen) ){
	                        bump = 1;
	                        break;
	                    }
	                    if( map[initY+tLen][initX+1+i] == 2)
	                        onO++;
	                }
					
					dx = 1, dy = 1;    
            }
 
            //printf("%d %d\n", bump, onO);    
            if(onO > 1 || bump == 1)  continue;
 
            if(dx == 1)
                for(int i = 0;i < tLen;i++){
                    map[initY+dy+i][initX+tHei] = 1;
                    map[initY+i][initX] = 0;
                }
            else if(dx == -1)
                for(int i = 0;i < tLen;i++){
                    map[initY+i][initX-1] = 1;
                    map[initY+i][initX+tHei-1] = 0;
                }
            if(dy == 1)
                for(int i = 0;i < tHei;i++){
                    map[initY+tLen][initX+dx+i] = 1;
                    map[initY][initX+i] = 0;
                }
            else if(dy == -1)
                for(int i = 0;i < tHei;i++){
                    map[initY-1][initX+i] = 1;
                    map[initY+tLen-1][initX+i] = 0;
                }
 
            initY += dy;
            initX += dx;
        }
    }
 
 
    return 0;
}
