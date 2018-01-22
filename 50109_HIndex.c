#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char name[16];
	int cite;
}Pair;
Pair papers[20000], ans[20000];

int cmp(const void *a, const void *b){
	Pair *c = (Pair *)a, *d = (Pair *)b;

	if( strcmp(c->name, d->name) )
		return strcmp(c->name, d->name);
	else if(c->cite > d->cite)
		return -1;
	else
		return 1;
}

int main(void){
	int pC = 0;
	while( scanf("%s %d", papers[pC].name, &papers[pC].cite) == 2 )  pC++;
	qsort(papers, pC, sizeof(Pair), cmp);

	int aC = 0, idx = 0;
	char nameCheck[16];
	strcpy(nameCheck, papers[0].name);

	while(idx < pC){
		int hidx = 0;

		while( !strcmp(nameCheck, papers[idx].name) && idx < pC ){
			if(papers[idx].cite >= hidx+1)  hidx++;
			idx++;
		}

		strcpy(ans[aC].name, nameCheck);
		ans[aC++].cite = hidx;

		if(idx < pC)  strcpy(nameCheck, papers[idx].name);
	}

	qsort(ans, aC, sizeof(Pair), cmp);
	for(int i = 0;i < aC;i++)
		printf("%s %d\n", ans[i].name, ans[i].cite);

	return 0;
}