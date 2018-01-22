#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
 
int ship[32780][260] = {0};
int count[32780] = {0};
 
int main(void){
    int N, E;
    scanf("%d%d", &N, &E);
 
    int va, vb;
    for(int i = 0;i < E;i++){
        scanf("%d%d", &va, &vb);
 
        ship[va][ count[va]++ ] = vb;
        ship[vb][ count[vb]++ ] = va;
    }
 
    bool rec[32780];
    memset(rec, false, sizeof(rec));
 
    int hold;
    while( scanf("%d", &hold) == 1 ){
        rec[hold] = true;
        for(int i = 0;i < count[hold];i++)
            rec[ ship[hold][i] ] = true;   
    }
 
    for(int i = 0;i < N;i++)
        if(rec[i] == false)
            printf("%d\n", i);
 
    return 0;
}