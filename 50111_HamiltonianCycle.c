#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
 
bool visited[1024];
short ans[1024], connect[1024][1024], cnt[1024];
int cities;
 
int cmp(const void *a, const void *b){
    return *(short *)a - *(short *)b;
}
 
void DFS(int start, int now, int step){
    ans[step] = now;
 
    if(step == cities-1){
        for(int i = 0;i < cnt[now];i++)
            if(connect[now][i] == start){
                for(int j = 0;j <= step;j++)
                    printf("%d ", ans[j]);
                printf("%d", start);
                exit(0);
            }
 
        return;
    }
 
    for(int i = 0;i < cnt[now];i++)
        if( !visited[ connect[now][i] ] ){
            visited[ connect[now][i] ] = true;
            DFS(start, connect[now][i], step+1);
            visited[ connect[now][i] ] = false;
        }
 
    return;
}
 
int main(void){
    memset(cnt, 0, sizeof(cnt));
    memset(visited, false, sizeof(visited));
 
    int edges; scanf("%d %d", &cities, &edges);
    while(edges--){
        int va, vb;
        scanf("%d %d", &va, &vb);
 
        connect[va][ cnt[va]++ ] = vb;
        connect[vb][ cnt[vb]++ ] = va;
    }
 
    for(int i = 0;i < cities;i++)
        qsort(connect[i], cnt[i], sizeof(short), cmp);
 
    for(int i = 0;i < cities;i++){
        visited[i] = true;
        DFS(i, i, 0);
        visited[i] = false;
    }
 
    puts("NO SOLUTION");
 
    return 0;
}