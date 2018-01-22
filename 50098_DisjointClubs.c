#include <stdio.h>
#include <string.h>
 
unsigned long long club[128];
int clubs, target, ans[128], success = 0;
 
void compute(int pos, int step, unsigned long long already){
    if(step == target && !success){
        for(int i = 0;i < target;i++)
            printf("%d\n", ans[i]);
 
        success = 1;
        return;
    }
    if( (clubs-pos) < (target-step) )
        return;
 
    if(!success){
        if( (club[pos] & already) == 0 ){
            ans[step] = pos;
            compute(pos+1, step+1, already | club[pos]);
            ans[step] = -1;
        }
 
        compute(pos+1, step, already);
    }
 
    return;
}
 
int main(void){
    memset(club, 0, sizeof(club));
    for(int i = 0;i < 128;i++)
        ans[i] = -1;
 
    scanf("%d %d", &clubs, &target);
    for(int i = 0;i < clubs;i++){
        int members;
        scanf("%d", &members);
 
        while(members--){
            int inman;
            scanf("%d", &inman);
 
            club[i] += (unsigned long long)1 << inman;
        }
    }
 
    compute(0, 0, 0);
 
    return 0;
}