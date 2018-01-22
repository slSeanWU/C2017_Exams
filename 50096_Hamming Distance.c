#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
int main(void){
    int validCount, storeCount, testCount;
    scanf("%d%d%d", &validCount, &storeCount, &testCount);
 
    unsigned long long store[storeCount];
    int count = 0;
    unsigned long long input;
 
 
    for(int i = 0;i < storeCount;i++){
        store[i] = 0;
        scanf("%llu", &input);
 
        for(int j = 7;j >= 0 && count < validCount;j--){
            unsigned long long toAdd = (input>>8*j)%256;
            store[i] = store[i] | toAdd<<8*j;
            count++;
        }
 
        if(count >= validCount)
            break;
    }
 
    while(testCount--){
        unsigned long long test;
        scanf("%llu", &test);
 
        bool correct = false;
        for(int i = 0;i < validCount;i++){
            int block = i/8;
            int shift = 8*(7-(i%8));
 
            unsigned long long check = (store[block]>>shift)%256;
            if( test ==  check ){
                correct = true;
                break;
            }
        }
 
        if(correct){
            printf("%llu\n", test);
            continue;
        }
 
        bool diff1 = false;
        for(int i = 0;i < validCount;i++){
            int block = i/8;
            int shift = 8*(7-(i%8));
 
            unsigned long long check = (store[block]>>shift)%256;
            unsigned long long Hamdis = test^check;
 
            for(int j = 0;j < 8;j++)
                if(1<<j == Hamdis)
                    diff1 = true;
 
            if(diff1){
                printf("%llu\n", check);
                break;
            }
        }
    }
    return 0;
}
