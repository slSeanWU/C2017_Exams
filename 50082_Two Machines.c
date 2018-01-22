#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
int main(void){
    int aBusy = 0, bBusy = 0;
    int come;
    int aDur, bDur;
 
    while( scanf("%d", &come) == 1 ){
        scanf("%d%d", &aDur, &bDur);
 
        if(come >= aBusy){
            come += aDur;
            aBusy = come;
        }
        else{
            come = aBusy+aDur;
            aBusy = come;
        }
 
        if(come >= bBusy){
            come += bDur;
            bBusy = come;
        }
        else{
            come = bBusy+bDur;
            bBusy = come;
        }
 
        //printf("%d %d\n", aBusy, bBusy);
        printf("%d\n", come);
    }
 
    return 0;
}
