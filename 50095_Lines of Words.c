#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char element[10000384], line[500000];
int e_index = 0;

int main(void){
	int N;
	scanf("%d", &N);
	getchar();
	
	char *first[16384];
	int f_index = 0, f_count[N+1], w_count = 0;
	
	for(int i = 0;i < N;i++){
		memset(line, 0, sizeof(line));
		f_count[i] = w_count;
		
		fgets(line, 10000384, stdin);
		int len = strlen(line), l_index = 0;
		while( sscanf(&line[l_index], "%s", &element[e_index]) == 1 ){
			first[f_index++] = &element[e_index];
			
			int len = strlen( &element[e_index] );
			
			l_index += len+1;
			e_index += len+1;
			w_count++;
		}
	}
	f_count[N] = w_count;

	int Q;
	scanf("%d", &Q);
	while(Q--){
		int s1, f1, s2, f2;
		scanf("%d%d%d%d", &s1, &f1, &s2, &f2);
		
		char *tmp = first[ f_count[s2]+f2 ];
		first[ f_count[s2]+f2 ] = first[ f_count[s1]+f1 ];
		first[ f_count[s1]+f1 ] = tmp;
	}
	
	for(int i = 0;i < N;i++){
		printf("%s", first[ f_count[i] ]);
		
		for(int j = 1;j < f_count[i+1]-f_count[i];j++ )
			printf(" %s", first[ f_count[i]+j ]);
			
		printf("\n");
	}
			
	return 0;
}

