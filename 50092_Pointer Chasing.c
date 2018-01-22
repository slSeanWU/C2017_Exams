#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>
 
void chasing(int **A[], int a, int *B[], int b, int C[], int c){
    for(int i = 0;i < a;i++)
        A[i] = NULL;
    for(int i = 0;i < b;i++)
        B[i] = NULL;
 
    char cmd[72];
    while( fgets(cmd, 72, stdin) != NULL ){
        bool invalid = false;
        char ch1 = 0, ch2 = 0;
        int p1 = 0, p2 = 0;
        bool yp1 = false, yp2 = false; 
 
        int len = strlen(cmd), index = 0;
 
        while( isspace(cmd[index]) && index < len)
            index++;
 
 
        if( cmd[index] == 'A' || cmd[index] == 'B' )
            ch1 = cmd[index];
        else
            invalid = true;
    
        index++;
 
        while( isspace(cmd[index]) && index < len)
            index++;
 
        while( isdigit(cmd[index]) && index < len){
            yp1 = true;
            p1 = 10*p1 + cmd[index]-'0';
            index++; 
        }
        if( (ch1 == 'A' && p1 >= a) || (ch1 == 'B' && p1 >= b) )
            invalid = true;
 
        while( isspace(cmd[index]) && index < len)
            index++;
 
        if( (ch1 == 'A' && cmd[index] == 'B') || ( ch1 == 'B' && cmd[index] == 'C' ) )
            ch2 = cmd[index];
        else
            invalid = true;

        index++;
 
 
        while( isspace(cmd[index]) && index < len)
            index++;
 
        while( isdigit(cmd[index]) && index < len){
            yp2 = true;
            p2 = 10*p2 + cmd[index]-'0';
            index++; 
        }
        if( (ch2 == 'B' && p2 >= b) || (ch2 == 'C' && p2 >= c) )
            invalid = true;
 
        while(index < len){
            if( !isspace( cmd[index] ) ){
                invalid = true;
                break;
            }
            index++;
        }
 
        if(ch1 == 0 || ch2 == 0 || !yp1 || !yp2)
            invalid = true;
     
        if(invalid){
            puts("0");
            continue;
        }
 
        else
            puts("1");
        if(ch1 == 'A')
            A[p1] = &(B[p2]);
        else
            B[p1] = &(C[p2]);
    }
 
    return;
}

int main() {
        int a = 5, b = 4, c = 3;
        int **A[5] = {}, *B[4] = {}, C[3] = {2, 1, 4};
        chasing(A, a, B, b, C, c);
 
        int **ansA[5] = {} ,*ansB[4] = {};
        for (int i = 0; i < a; i++)
                ansA[i] = NULL;
        for (int i = 0; i < b; i++)
                ansB[i] = NULL;
        ansA[2] = &B[1], ansA[3] = &B[0], ansB[1] = &C[1], ansB[2] = &C[0];
        /*Check A*/
        for (int i = 0; i < a; i++)
                if (A[i] != ansA[i] )
                        printf("A[%d] wrong answer!\n", i);
 
        /*Check B*/
        for (int i = 0; i < b; i++)
                if (B[i] != ansB[i] )
                        printf("B[%d] wrong answer!\n", i);
        return 0;
}
