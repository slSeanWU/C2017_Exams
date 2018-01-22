#include <stdio.h>
#include <stdlib.h>

int main(void){
	int a, b;
	scanf("%d%d", &a, &b);
	
	printf("%d\n", (a+b)*(b-a+1)/2);
	printf("%d\n", a+b + 2*(b-a+1) -4);
	
	return 0;
}

