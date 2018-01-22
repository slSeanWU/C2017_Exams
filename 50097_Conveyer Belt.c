#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1048576

long long int belt[MAXSIZE];

void printBlock(long long int *block){
	unsigned long long num = *block;
	
	for(int i = 63;i >= 0;i--)
		printf("%d", (num>>i) & 1);
		
	printf("\n");
	
	return;	
}

void transmission(long long int belt[],int N,int T){
	long long temp[N];
	for(int i = 0;i < N;i++)
		temp[i] = 0;
	
	if(T%64 == 0){
		int shift = T/64;
		for(int i = shift;i < shift+N;i++)
			temp[i-shift] = belt[i%N];
	}
	else{
		int numShift = T/64;
		int bitShift = T%64;
		
		for(int i = numShift;i < numShift+N;i++){
			temp[i-numShift] = belt[i%N]<<bitShift;

			long long toAdd = belt[(i+1)%N] >> (64-bitShift);
			long long mask = 0xffffffffffffffff << bitShift;
			mask = ~mask;
			
			temp[i-numShift] += (mask & toAdd);
		}	
	}
	
	for(int i = 0;i < N;i++)
		belt[i] = temp[i];
		
	return;
}

int main(){
    int N,T;
    scanf("%d%d",&N,&T);
    for(int i=0;i<N;i++){
    	scanf("%lld",&belt[i]);	
    	printBlock(&belt[i]);
	}
        
    transmission(belt,N,T);
    for(int i=0;i<N;i++)
        printf("%lld%s",belt[i],i==N-1?"":" ");
    return 0;
}

