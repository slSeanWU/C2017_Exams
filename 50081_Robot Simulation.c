#include <stdio.h>
#include <stdlib.h>

int main(void){
	int n, m;
	scanf("%d%d", &n, &m);
	
	int cmd, x=0, y=0;
	printf("%d\n%d\n", x, y);
	
	while( scanf("%d", &cmd) == 1){
		
		switch( cmd%5 ){
			case 0:
				continue;
			case 1:
				if( x+cmd >= n )  continue;
				x += cmd;	
				break;
			case 2:
				if( x-cmd < 0 )  continue;
				x -= cmd;	
				break;
			case 3:	 
				if( y+cmd >= m )  continue;
				y += cmd;	
				break;
			case 4:
				if( y-cmd < 0 )  continue;
				y -= cmd;
		}
		
		printf("%d\n%d\n", x, y);	
	}
	
	return 0;
}

