#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct{
    int h, w;
    char name[64];
}Student;
Student stu[100000];
 
int cmp(const void *a, const void *b){
    Student *c = (Student *)a, *d = (Student *)b;
 
    double heightA = (double)c->h / 100, heightB = (double)d->h / 100;
    double weightA = (double)c->w, weightB = (double)d->w;
    double BMIa = weightA/(heightA*heightA), BMIb = weightB/(heightB*heightB);
 
    if(BMIa < BMIb)    return -1;
    else if(BMIa > BMIb) return 1;
    else if(c->w < d->w) return -1;
    else if(c->w > d->w) return 1;
    else if(c->h < d->h) return -1;
    else if(c->h > d->h) return 1;
    else return strcmp(c->name, d->name);
}
 
int main(void){
    int N;
    scanf("%d", &N);
 
    for(int i = 0;i < N;i++)
        scanf("%s %d %d", stu[i].name, &stu[i].h, &stu[i].w);
 
    qsort(stu, N, sizeof(Student), cmp);
 
    for(int i = 0;i < N;i++)
        printf("%s %d %d\n", stu[i].name, stu[i].h, stu[i].w);
 
    return 0;
}