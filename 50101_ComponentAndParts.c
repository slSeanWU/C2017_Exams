#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLENGTH 16
#define MAXCOMPONENT 64

typedef struct{
    char name[MAXLENGTH];
    int numComponent;
    int componentPartList[MAXCOMPONENT];
    int price;
}ComponentPart;

int ansPrice;

void PriceAddup(int pos, ComponentPart list[]){
	if( list[pos].numComponent == 0 ){
		ansPrice += list[pos].price;
		return;
	}
	else{
		for(int i = 0;i < list[pos].numComponent;i++)
			PriceAddup(list[pos].componentPartList[i], list);
	}

	return;
}

int cmp(const void *a, const void *b){
    ComponentPart *c = (ComponentPart *)a;
    ComponentPart *d = (ComponentPart *)b;

    return ( strcmp(c->name, d->name) );
}

void findPrice(int N,ComponentPart list[]){
	for(int i = 0;i < N;i++)
        if(list[pos].numComponent != 0){
    		ansPrice = 0;
    		PriceAddup(i, list);
    		list[i].price = ansPrice;
        }

    qsort(list, N, sizeof(ComponentPart), cmp);

    for(int i = 0;i < N;i++)
        printf("%s %d\n", list[i].name, list[i].price);

    return;
}

int main(){
    int N;
    scanf("%d",&N);
    ComponentPart list[N];
    for(int i=0;i<N;i++){
        scanf("%s%d",list[i].name,&list[i].numComponent);
        if(list[i].numComponent){
            for(int j=0;j<list[i].numComponent;j++)
                scanf("%d",&list[i].componentPartList[j]);
            list[i].price=0;
        }
        else
            scanf("%d",&list[i].price);
    }
    findPrice(N,list);
    return 0;
}