#include <stdio.h>
#include <stdlib.h>

void mirror(unsigned char *target, unsigned char base){
	for(int i = 0;i < 8;i++){
		unsigned char toAdd = (base >> i) & 1;
		*target += ( toAdd << (7-i) );
	}

	return;
}

int main(void){
	FILE *fin, *fout;
	char sin[32], sout[32];
	int shift;

	scanf("%s %s %d", sin, sout, &shift);
	fin = fopen(sin, "rb"), fout = fopen(sout, "wb");

	fseek(fin, 0, SEEK_END);
	long long size = ftell(fin);
	fseek(fin, 0, SEEK_SET);

	for(long long i = 0;i < size;i++){
		unsigned char read, write = 0;
		fseek(fin, i, SEEK_SET);
		fread(&read, 1, 1, fin);

		mirror(&write, read);
		printf("%p\n", write);
		printf("%d\n", (2*size-1-i - shift)%size);

		fseek(fout, (2*size-1-i - shift)%size, SEEK_SET);
		fwrite(&write, 1, 1, fout);
	}

	fclose(fin), fclose(fout);
	
	return 0;
}