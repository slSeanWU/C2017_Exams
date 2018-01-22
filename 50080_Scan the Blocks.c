#include <stdio.h>
#include <stdlib.h>
 
int main(void){
    int n;
 
    while(scanf("%d", &n) == 1){
        int id, b;
        int input;
        scanf("%d", &input);
 
        int min = input, max = input;
        for(id = 1;id < n;id++){
            if(scanf("%d", &input) == 1){
                if(input > max)  max = input;
                else if(input < min)  min = input;
            }
 
            else break;
        }
 
        if(id == n)
            printf("%d\n", max);
        else
            printf("%d\n", min);
    }
 
    return 0;
}
