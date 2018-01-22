#include <stdio.h>
#include <stdlib.h>

int main(void){
	int n;
	scanf("%d", &n);
	
	int w[n], Nfound = 1;
	for(int i = 0;i < n;i++)
		scanf("%d", &w[i]);
	
	int fulc;	
	for(int i = 0;i < n && Nfound;i++){
		int ltau, rtau;
		
		for(fulc = 0;fulc < n && Nfound;fulc++){
			ltau = 0, rtau = 0;
			
			for(int l = 0;l < fulc;l++)
				ltau += w[l]*(fulc-l);
			for(int r = fulc+1;r < n;r++)
				rtau += w[r]*(r-fulc);
				
			if(ltau == rtau)
				Nfound = 0;
		}
	
		if(Nfound){
			int tmp = w[i];
			w[i] = w[n-1-i];
			w[n-1-i] = tmp;
		}
	}
	
	for(int i = 0;i < fulc-1;i++)
		printf("%d ", w[i]);
	printf("v");
	for(int i = fulc;i < n;i++)
		printf(" %d", w[i]);
		
	return 0;
}

