#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isFriend[16][16];
unsigned short placed = 0;
short rec[16];
int N, M;
int ans = 2147483647;

void findAns(int step, int nowDis){
	for(int i = 0;i < step-1;i++)
		if( isFriend[ rec[step-1] ][ rec[i] ] )
			nowDis += (step-1) - i;

	if(nowDis >= ans)
		return;

	if(step == N){
		if( nowDis < ans )  ans = nowDis;
		return;
	}

	for(int i = 0;i < N;i++)
		if( !( (placed >> i) & 1 ) ){
			placed += (1 << i);
			rec[step] = i;
			findAns(step+1, nowDis);
			placed -= (1 << i);
		}

	return;
}

int main(void){
	scanf("%d %d", &N, &M);
	memset(isFriend, false, sizeof(isFriend));

	while(M--){
		int va, vb;
		scanf("%d %d", &va, &vb);
		isFriend[va][vb] = isFriend[vb][va] = true;
	}

	findAns(0, 0);
	printf("%d", ans);

	return 0;
}