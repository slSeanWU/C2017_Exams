#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
 
struct task{
    int time, step_total;
    int seq[505][2]; //  [0] for machine No., [1] for the time needed.
    int step_now;
};
 
int main(void){
    int n, m;
    scanf("%d%d", &n, &m);
 
    int mReady[505];
    struct task jobs[m];
    memset(mReady, 0, sizeof(mReady));
 
 	// Input task data
    for(int i = 0;i < m;i++){
        scanf("%d%d", &jobs[i].time, &jobs[i].step_total);
 
        for(int j = 0;j < jobs[i].step_total;j++)
            scanf("%d%d", &(jobs[i].seq[j][0]), &(jobs[i].seq[j][1]));  
 
        jobs[i].step_now = 0;
    }
 
    int completed = 0;
    while(completed < m){
        int hold = 10000000;
        int exe;
 
        // Greedy principle: Examine the completion time of the next step of each task;
        //                   finding the earliest one.
        for(int i = 0;i < m;i++){
            if(jobs[i].step_now == jobs[i].step_total)
                continue;
 
            int tmp;
            int macNow = jobs[i].seq[ jobs[i].step_now ][0];
 
            if(jobs[i].time > mReady[macNow])
                tmp = jobs[i].time + jobs[i].seq[ jobs[i].step_now ][1];
            else
                tmp = mReady[macNow] + jobs[i].seq[ jobs[i].step_now ][1];
 
            if(tmp < hold){
                hold = tmp;
                exe = i;
            }
        }
 
        // Execution
        int macUse = jobs[exe].seq[ jobs[exe].step_now ][0];
        int end;
 
        if(jobs[exe].time > mReady[macUse])
            end = jobs[exe].time + jobs[exe].seq[ jobs[exe].step_now ][1];
        else
            end = mReady[macUse] + jobs[exe].seq[ jobs[exe].step_now ][1];
 
        jobs[exe].time = end;
        mReady[macUse] = end;
        jobs[exe].step_now++;
        if(jobs[exe].step_now == jobs[exe].step_total)  completed++;
    }
 
    for(int i = 0;i < m;i++)
        printf("%d\n", jobs[i].time);
 
    return 0;
}
