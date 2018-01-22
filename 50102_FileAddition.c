#include <stdio.h>
 
 
int main(void){
    char name1[32], name2[32];
    scanf("%s %s", name1, name2);
 
    char outname[32];
    scanf("%s", outname);
 
    FILE *fout = fopen(outname, "wb");
 
    FILE *f1, *f2;
    long long size1, size2;
 
    f1 = fopen(name1, "rb");
    fseek(f1, 0, SEEK_END);
    size1 = ftell(f1);
 
    f2 = fopen(name2, "rb");
    fseek(f2, 0, SEEK_END);
    size2 = ftell(f2);
 
    printf("%lld %lld\n", size1, size2);
    long long num = (size1 > size2)? size1:size2;
 
    int ign = 0;
    fwrite(&ign, 1, num, fout);
 
    unsigned int carry = 0;
    for(long long i = 0;i < num;i++){
        unsigned int toAdd = carry;
        unsigned char in1, in2;
 
        if(i >= size1){
            fseek(f2, -i-1, SEEK_END);
            fread(&in2, 1, 1, f2);
            toAdd += in2;
        }
        else if(i >= size2){
            fseek(f1, -i-1, SEEK_END);
            fread(&in1, 1, 1, f1);
            toAdd += in1;
        }
        else{
            fseek(f2, -(i+1), SEEK_END);
            fread(&in2, 1, 1, f2);
            toAdd += in2;
 
            fseek(f1, -(i+1), SEEK_END);
            fread(&in1, 1, 1, f1);
            toAdd += in1;
        }
 
        if(toAdd >= 256)  carry = 1;
        else carry = 0;
 
        //printf("%d %d\n %d\n", in1, in2, (unsigned char)toAdd);
 
        unsigned char toWrite = (unsigned char)toAdd;
 
        fseek(fout, num-(i+1), SEEK_SET);
        fwrite(&toWrite, 1, 1, fout);
    }
 
 
    fclose(f1);
    fclose(f2);
    fclose(fout);
 
    return 0;
}