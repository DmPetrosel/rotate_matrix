#include <stdio.h>
#include <stdlib.h>
int input(int **data, int yy, int xx);
void destroy(int **data, int yy);
void output(int **data, int yy, int xx);
int main(){
    int yy, xx;
    if(scanf("%d",&yy)!=1 || yy <= 0){
        printf("n/a");
        return 0;
    }
    if(scanf("%d",&xx)!=1 || xx <= 0){
        printf("n/a");
        return 0;
    }
    int **data = (int**)malloc(yy*sizeof(int*));
    for(int y = 0; y < yy; y++){
        data[y] = (int*)malloc(xx*sizeof(int));
    }
    if(!input(data, yy, xx)){
        printf("n/a");
    }
    else{
        output(data, yy, xx);
    }
    destroy(data, yy);
    return 0;
}
int input(int **data, int yy, int xx){
    for(int y = 0; y < yy; y++){
        for(int x = 0; x < xx; x++){
            if(scanf("%d", (*(data+y)+x))!=1){
                return 0;
            }
        }
    }
    return 1;
}
void destroy(int **data, int yy){
    for(int y = 0; y < yy; y++){
        free(data[y]);
    }
    free(data);
}
void output(int **data, int yy, int xx){
    for(int y = 0; y < xx; y++){
        for(int x = yy - 1; x >=0; x--){
            printf("%d",data[x][y]);
            if(x > 0) printf(" ");
        }
        if(y < xx - 1) printf("\n");
    }
}


/*
2 2
1 2 3
4 5 6

4 1
5 2
6 3

*/