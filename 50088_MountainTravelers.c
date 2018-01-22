#include <stdbool.h>
#include <string.h>
 
bool inbound(int r, int c, int N, int M){
    if(r < 0 || r >= N || c < 0 || c >= M)
        return 0;
    else
        return 1;
}
 
void travel(int map[1024][1024], int N, int M, int A_r, int A_c, int B_r, int B_c, int directionA[], int directionB[]){
 
    int gor[] = {0, 0, 1, -1, 1, -1, -1, 1};
    int goc[] = {1, -1, 0, 0, 1, -1, 1, -1};
 
    bool visited[1024][1024];
    memset(visited, 0, sizeof(visited));
 
    int goA = 1, goB = 1;
    int Acount = 0, Bcount = 0;
 
    visited[A_r][A_c] = 1;
    visited[B_r][B_c] = 1;
 
    while(goA == 1 || goB == 1){
        int Aup = 0, Bdown = 0;
        int tmpA = -1, tmpB = -1;
        if(goA){
            for(int i = 0;i < 8;i++){
                if(inbound(A_r+gor[i], A_c+goc[i], N, M) && map[A_r+gor[i]][A_c+goc[i]] - map[A_r][A_c] > Aup){
                    tmpA = i;
                    Aup = map[A_r+gor[i]][A_c+goc[i]] - map[A_r][A_c];
                }
            }
        }
 
        if(goB){
            for(int i = 0;i < 8;i++){
                if(inbound(B_r+gor[i], B_c+goc[i], N, M) && map[B_r+gor[i]][B_c+goc[i]] - map[B_r][B_c] < Bdown){
                    tmpB = i;
                    Bdown = map[B_r+gor[i]][B_c+goc[i]] - map[B_r][B_c];
                }
            }
        }
 
        if(tmpA == -1)
            goA = 0;
        if(tmpB == -1)
            goB = 0;
 
        int onA = 0, onB = 0;   
        if(goA && visited[A_r+gor[tmpA]][A_c+goc[tmpA]] )   
            onA = 1;
        if(goB && visited[B_r+gor[tmpB]][B_c+goc[tmpB]] )
            onB = 1;
 
        if(tmpA >= 0 && tmpB >= 0 && A_r+gor[tmpA]==B_r+gor[tmpB] && A_c+goc[tmpA]==B_c+goc[tmpB])
            onA = 1, onB = 1;
 
        if(goA){
            directionA[Acount++] = tmpA;
            A_r = A_r+gor[tmpA];
            A_c = A_c+goc[tmpA];
            visited[A_r][A_c] = 1;
 
            if(onA){
                goA = 0;
                directionA[Acount++] = -1;
            }
 
        }
        else
            directionA[Acount++] = -1;
 
        if(goB){
            directionB[Bcount++] = tmpB;
            B_r = B_r+gor[tmpB];
            B_c = B_c+goc[tmpB];
            visited[B_r][B_c] = 1;
 
            if(onB){
                goB = 0;
                directionB[Bcount++] = -1;
            }
 
        }
        else
            directionB[Bcount++] = -1;
    }
 
    return;
}

// main program provided for testing
int main() {
    int N, M;
    int map[1024][1024];
    int A_r, A_c, B_r, B_c;
    int directionA[1024], directionB[1024];
 
    scanf("%d%d", &N, &M);
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }
 
    scanf("%d%d%d%d", &A_r, &A_c, &B_r, &B_c);
 
    travel(map, N, M, A_r, A_c, B_r, B_c, directionA, directionB);
 
    int i = 0;
    while (directionA[i] != -1) {
        printf("%d ", directionA[i]);
        i++;
    }
    printf("-1\n");
    i = 0;
    while (directionB[i] != -1) {
        printf("%d ", directionB[i]);
        i++;
    }
    printf("-1\n");
 
    return 0;
}