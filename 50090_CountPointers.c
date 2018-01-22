#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
 
struct pack{
    int num, count;
};
 
void count(int **p[]){
    int *hold[520];
    int holdC = 0;
    struct pack data[520];
 
    for(int i = 0;i < 520;i++)
        data[i].count = 0;
 
    for(int i = 0;p[i] != NULL;i++){
        int *tmp = *p[i];
 
        int check;
        for(check = 0;check < holdC;check++)
            if(tmp == hold[check]){
                data[check].count++;
                break;
            }
 
        if(check == holdC){
            hold[ holdC ] = tmp;
            data[holdC].num = *(*p[i]);
            data[holdC].count++;
            holdC++;
        }
    }
 
    for(int i = holdC-2;i >= 0;i--)
        for(int j = 0;j <= i;j++){
            if( data[j].count > data[j+1].count ){
                struct pack temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
            else if( data[j].count == data[j+1].count && data[j].num > data[j+1].num ){
                struct pack temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
 
    for(int i = 0;i < holdC;i++)
        printf("%d %d\n", data[i].num, data[i].count);
 
    return;
}

// main program provided for testing
#define MAX_SIZE_PTRARRAY 512
#define MAX_NUM_PTR 512
#define MAX_NUM_INTVAR 512
 
int main(){
  int **ptrArray[MAX_SIZE_PTRARRAY] = {};
  int  *intPtr[MAX_NUM_PTR];
  int   intVar[MAX_NUM_INTVAR];
 
  intVar[0] = 7;
  intVar[1] = 7;
  intVar[2] = 6;
  ptrArray[0] = &intPtr[0];
  ptrArray[1] = &intPtr[1];
  ptrArray[2] = &intPtr[2];
  ptrArray[3] = &intPtr[2];
  ptrArray[4] = &intPtr[3];
  ptrArray[5] = &intPtr[4];
  ptrArray[6] = NULL;
  intPtr[0] = &intVar[0];
  intPtr[1] = &intVar[1];
  intPtr[2] = &intVar[2];
  intPtr[3] = &intVar[2];
  intPtr[4] = &intVar[1];
 
  count(ptrArray);
 
  return 0;
}