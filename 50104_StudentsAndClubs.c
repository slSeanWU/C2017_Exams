#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct member{
    char name[50];
    struct member *mleft, *mright;
}Member;
 
typedef struct club{
    char clubname[50], leader[50];
    struct member *inmen;
    struct club *cleft, *cright;
}Club;
 
Club * buildClub(Club *root, char L[], char N[]){
    Club *current;
      if (root == NULL) {
        current = (Club *)malloc( sizeof(Club) );
        strcpy(current->leader, L);
        strcpy(current->clubname, N);
 
        current->inmen = NULL;
        current->cleft = NULL;
        current->cright = NULL;
 
        return(current);
    }
 
    if ( strcmp(N, root->clubname) < 0 ) 
          root->cleft = buildClub(root->cleft, L, N);
    else if( strcmp(N, root->clubname) > 0 )
          root->cright = buildClub(root->cright, L, N);
 
    return(root);
}
 
Member * addMeminClub(Member *root, char name[]){
    Member *current;
 
    if (root == NULL) {
        current = (Member *)malloc( sizeof(Member) );
        strcpy(current->name, name);
        //printf("%s\n", name);
 
        current->mleft = NULL;
        current->mright = NULL;
 
        return(current);
    }
 
    if ( strcmp(name, root->name) < 0 ) 
          root->mleft = addMeminClub(root->mleft, name);
    else
          root->mright = addMeminClub(root->mright, name);

    return root;
}
 
void addMem(Club *root, char N[], char C[]){
 
    if ( strcmp(C, root->clubname) < 0 )
        addMem(root->cleft, N, C);
    else if ( strcmp(C, root->clubname) > 0 )
        addMem(root->cright, N, C);
    else
        root->inmen = addMeminClub(root->inmen, N);
 
    return;
}
 
int findClub(Club *root, char N[], char C[]){
    if( root == NULL )
        return -1;
 
    int ret;
    if ( strcmp(C, root->clubname) < 0 )
        ret = findClub(root->cleft, N, C);
    else if ( strcmp(C, root->clubname) > 0 )
        ret = findClub(root->cright, N, C);
    else{
        strcpy(N, root->leader);
        //printf("found!! %s\n", C);
        return 1;
    }
 
    return ret;
}
 
int findMeminClub(Member *root, char name[]){
    if(root == NULL)
        return 0;
 
    int ret;
    if( !strcmp(name, root->name) )
        return 1;
    else if ( strcmp(name, root->name) < 0 ) 
          ret = findMeminClub(root->mleft, name);
    else if( strcmp(name, root->name) > 0 ) 
          ret = findMeminClub(root->mright, name);
 
    return ret;
}
 
int findMem(Club *root, char N[], char C[]){
 
    int ret;
    if ( strcmp(C, root->clubname) < 0 )
        ret = findMem(root->cleft, N, C);
    else if ( strcmp(C, root->clubname) > 0 )
        ret = findMem(root->cright, N, C);
    else{
        if( !strcmp(root->leader, N) )
            return 1;
        else{
            //printf("found!! %s\n", C);
            ret = findMeminClub(root->inmen, N);
        }
    }
 
    return ret;
}
 
int main(void){
    int CMD;
    scanf("%d", &CMD);
 
    Club *croot;
    while(CMD--){
        int ins;
        char name1[50], name2[50];
 
        scanf("%d %s %s", &ins, name1, name2);
 
        if(!ins)
            croot = buildClub(croot, name1, name2);
        else{
            addMem(croot, name1, name2);
        }
    }
 
    int Q;
    scanf("%d", &Q);
 
    while(Q--){
        int ins;
        scanf("%d", &ins);
 
        if(!ins){
            char Cname[50];
            scanf("%s", Cname);
 
            char Lname[50];
            int success = findClub(croot, Lname, Cname);
 
            if( success == -1 )
                puts("None");
            else
                puts(Lname);
        }
        else if(ins == 1){
            char name[50], club[50];
            scanf("%s %s", name, club);
 
            char ign[50] = {0};
            int foundClub = findClub(croot, ign, club);
 
            if( foundClub == -1 ){
                puts("-1");
                continue;
            }
 
            int success = findMem(croot, name, club);
            printf("%d\n", success);
        }
 
    }
    return 0;
}