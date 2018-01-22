#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>
 
int main(void){
    char ans[1036] = {0};
    scanf("%s", ans);
 
    char cmd[1036];
    while( scanf("%s", cmd) == 1 ){
        if(cmd[0] == 'p')
            printf("%s\n", ans);
 
        else if(cmd[0] == 's'){
            char deli = cmd[1];
 
            char target[512] = {0}, sub[512] = {0};
            int index = 2;
            int tlen = 0, slen = 0;
            while( cmd[index] != deli ){
                target[tlen++] = cmd[index];
                index++;
            }
 
            index++;
 
            while( cmd[index] != deli ){
                sub[slen++] = cmd[index];
                index++;
            }
 
            char *ptr = strstr(ans, target);
            if(ptr != NULL){
                char tmp[1036] = {0};
                strncpy(tmp, ans, ptr-ans);
                strcat(tmp, sub);
                strcat(tmp, ptr+tlen);
                strcpy(ans, tmp);
            } 
        }
    }
    return 0;
}
