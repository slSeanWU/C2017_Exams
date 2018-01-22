#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int *first[128][128];
int **second[128];

int ***constructTable(int A[], int B[]){
	int B_index = 0, i;
	 
	for(i = 0;A[i] != 0;i++){
		int sectors = A[i];
		
		for(int j = 0;j < sectors;j++){
			first[i][j] = &( B[ B_index ] );
			
			while( B[ B_index++ ] != 0);
		}
		
		first[i][sectors] = NULL;
		second[i] = &( first[i][0] );
	}
	second[i] = NULL;
	
	int ***ptr = &( second[0] );
	
	return ptr;
}

int main(){
    int N, M;
    int A[100] = {}, B[5000] = {};
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    for(int i = 0; i < M; i++)
        scanf("%d", &B[i]);
 
    int ***ptr;
    ptr = constructTable(A, B);
    for(int i = 0; *(ptr+i) != NULL; i++)
        for(int j = 0; j < A[i]; j++)
            for(int k = 0; *(*(*(ptr+i)+j)+k) != 0; k++)
                printf("%d ", *(*(*(ptr+i)+j)+k));
    return 0;
}

