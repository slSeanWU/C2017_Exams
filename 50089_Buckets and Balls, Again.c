#include <stdio.h>
 
void place(int bucket[1024],int N,int ball[16384],int M,int method,int result[16384]){
	for(int i = 0;i < M;i++){
		int use = -1, min = 20000000, max = -1;
		
		if(method == 0){
			for(int j = 0;j < N;j++)
				if(ball[i] <= bucket[j]){
					use = j;
					break;
				}
		}
		
		else if(method == 1){
			for(int j = 0;j < N;j++)
				if(bucket[j]-ball[i] >= 0 && bucket[j]-ball[i] < min)
					use = j, min = bucket[j]-ball[i];
		}
		
		else{
			for(int j = 0;j < N;j++)
				if(bucket[j]-ball[i] >= 0 && bucket[j]-ball[i] >= max)
					use = j, max = bucket[j]-ball[i];
		}
		
		result[i] = use;
		if(use != -1)
			bucket[use] -= ball[i];
	}
	
	return;
} 

int main(void){
    int N,M,method;
    scanf("%d%d%d",&N,&M,&method);
    int buckets[N];
    for(int i=0;i<N;i++)
        scanf("%d",&buckets[i]);
    int balls[M];
    for(int i=0;i<M;i++)
        scanf("%d",&balls[i]);
    int result[M];
    place(buckets,N,balls,M,method,result);
    for(int i=0;i<M;i++)
        printf("%d%s",result[i],i==M-1?"":" ");
    return 0;
}
