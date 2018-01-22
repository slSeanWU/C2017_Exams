#include <stdio.h>
#include <stdlib.h>

int main(void){
	int a, b, r;
	scanf("%d%d%d", &a, &b, &r);
	
	int a_now = a, b_now = b;
	int input;
	
	if(r == 0){
		while(scanf("%d", &input) == 1){
			if(a_now >= input)
				a_now -= input;
			else if(b_now >= input)
				b_now -= input;
				
			printf("%d %d\n", a_now, b_now);
		}
	}
	else{
		while(scanf("%d", &input) == 1){
			if(input > a_now && input > b_now);
			
			else if(input > a_now)
				b_now -= input;
			else if(input > b_now)
				a_now -= input;
			else{
				if(a_now-input <= b_now-input) 
			 		a_now -= input;
				else
					b_now -= input;
			}
				
			printf("%d %d\n", a_now, b_now);
		}
	}
	return 0;
}

