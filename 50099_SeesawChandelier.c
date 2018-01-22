#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int seesaw[16384], total;
bool ans[16384];

void balance(int left, int right){
	if(right-left < 2)
		return;

	long long sumTau = 0, sumWeight = 0;
	for(int i = left;i <= right;i++){
		sumTau += seesaw[i]*(i-left);
		sumWeight += seesaw[i];
	}
	if(sumTau%sumWeight != 0)
		return;

	for(int i = left;i <= right;i++){
		if(sumWeight*(i-left) == sumTau){
			ans[i] = true;
			balance(left, i-1);
			balance(i+1, right);
			break;
		}
	}

	return;
}

int main(void){
	memset(ans, 0, sizeof(ans));

	scanf("%d", &total);
	for(int i = 0;i < total;i++)
		scanf("%d", &seesaw[i]);

	balance(0, total-1);

	for(int i = 0;i < total;i++)
		if(ans[i])
			printf("%d\n", i);

	return 0;
}