#include <stdio.h>
 
int main(void){
    int ax, ay, bx, by, cx, cy;
    scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &cx, &cy);
    int diffX, diffY;
 
    diffX = bx-ax;
    diffY = by-ay;
    printf("%d\n%d\n", cx+diffX, cy+diffY);
 
    diffX = cx-bx;
    diffY = cy-by;
    printf("%d\n%d\n", ax+diffX, ay+diffY);
 
    diffX = ax-cx;
    diffY = ay-cy;
    printf("%d\n%d\n", bx+diffX, by+diffY);
 
    return 0;
}