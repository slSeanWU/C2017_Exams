#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(void){
	int freq[26][26], T;
	char input[128];
	
	memset(freq, 0, sizeof(freq));
	scanf("%d", &T);
	
	while(scanf("%s", input) == 1){
		int len = strlen(input);
		
		for(int i = 0;i < len-1;i++)
			freq[ input[i]-'a' ][ input[i+1]-'a' ]++;
	}
	
	int max_pair = 0;
	char c1, c2;
	
	for(int i = 0;i < 26;i++)
		for(int j = 0;j < 26;j++){
			printf("%d%c", freq[i][j]," \n"[j == 25]);
			
			if( freq[i][j] > max_pair){
				max_pair = freq[i][j];
				c1 = i+'a';
				c2 = j+'a';
			}
		}
			
			
	char ans[32] = {0};
	bool used[26] = {0};
	
	ans[0] = c1, ans[1] = c2;
	used[c1-'a'] = used[c2-'a'] = true;
	int end = 1;
	
	bool found;
	while(end < 32){
		int max_next = 0;
		char next;
		found = false;
		
		for(int i = 0;i < 26;i++)
			if( freq[ ans[end]-'a' ][i] > max_next &&
				freq[ ans[end]-'a' ][i] > T &&
				!used[i] ){
					
				found = true;
				next = i+'a';
				max_next = freq[ ans[end]-'a' ][i];
			}
		
		if(found){
			ans[++end] = next;
			used[next-'a'] = true;
		}	
		else  break;
	}
		
	
	printf("%s", ans);
			
	return 0;
}

