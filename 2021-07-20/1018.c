#include <stdio.h>

int min(int a, int b){
    return a < b ? a : b;
}

int makeChess(char chess[50][50], int r, int c){
    int bcnt = 0;
    int wcnt = 0;

    char newChess[8][8];

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            newChess[i][j] = chess[r + i][c + j];
        }
    }

    // start with B
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(i % 2 == 0){
                if(j % 2 == 0){
                    if(newChess[i][j] != 'B'){
                        bcnt++;
                    }
                }
                else{
                    if(newChess[i][j] != 'W'){
                        bcnt++;
                    }
                }
            }
            else{
                if(j % 2 == 0){
                    if(newChess[i][j] != 'W'){
                        bcnt++;
                    }
                }
                else{
                    if(newChess[i][j] != 'B'){
                        bcnt++;
                    }
                }
            }
        }
    }

    // start with W
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(i % 2 == 0){
                if(j % 2 == 0){
                    if(newChess[i][j] != 'W'){
                        wcnt++;
                    }
                }
                else{
                    if(newChess[i][j] != 'B'){
                        wcnt++;
                    }
                }
            }
            else{
                if(j % 2 == 0){
                    if(newChess[i][j] != 'B'){
                        wcnt++;
                    }
                }
                else{
                    if(newChess[i][j] != 'W'){
                        wcnt++;
                    }
                }
            }
        }
    }

    return min(bcnt, wcnt);
}

int main(){
    int n, m;
    char chess[50][50];
    int res = 64;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf(" %c", &chess[i][j]);
        }
    }

    int cnt;
    for(int i = 0; i < n - 7; i++){
        for(int j = 0; j < m - 7; j++){
            cnt = makeChess(chess, i, j);
            res = min(cnt, res);
        }
    }

    printf("%d", res);

    return 0;
}