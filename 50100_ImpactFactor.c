#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXP 1024


typedef struct {
    char journalName[64];
    int numCitedPaper;
    int citedPaperIndex[1024];
} paper;
paper P[MAXP];

 
typedef struct journal{
    char journalName[64];
    int numPapers;
    int numCited;
}Journal;
Journal data[1024];
 
int getJourIndex(char check[], int bound){
    for(int i = 0;i < bound;i++)
        if( !strcmp(check, data[i].journalName) )
            return i;
 
    return bound;
}
 
int cmp(const void *a, const void *b){
    Journal *c = (Journal *)a;
    Journal *d = (Journal *)b;
 
    return strcmp(c->journalName, d->journalName);
}
void compute(paper P[], int N){
    int inWhichJournal[N], numofJournal = 0;
 
    memset(data, 0, sizeof(data));
 
    for(int i = 0;i < N;i++){
        int jour = getJourIndex(P[i].journalName, numofJournal);
 
        if(jour == numofJournal){
            strcpy( data[jour].journalName, P[i].journalName );
            numofJournal++;
        }
 
        inWhichJournal[i] = jour;
        data[jour].numPapers++;
    }
 
    for(int i = 0;i < N;i++)
        for(int j = 0;j < P[i].numCitedPaper;j++){
            int inJournal = inWhichJournal[ P[i].citedPaperIndex[j] ];
 
            data[ inJournal ].numCited++;
        }
 
    qsort(data, numofJournal, sizeof(Journal), cmp);
 
    for(int i = 0;i < numofJournal;i++)
        printf("%s %d/%d\n", data[i].journalName, data[i].numCited, data[i].numPapers);
 
    return;
}
int main() {
    int N;
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s%d", P[i].journalName, &P[i].numCitedPaper);
        for (int j = 0; j < P[i].numCitedPaper; j++)
            scanf("%d", &P[i].citedPaperIndex[j]);
    }
    compute(P, N);
    return 0;
}