#include <iostream>
#include <cstring>

using namespace std;

bool lineCheck(int sudoku[][10], int r, int c, int key){
    bool res = false;

    for(int i = 0; i < 9; i++){
        if(sudoku[r][i] == key){
            res = true;
            break;
        }
        if(sudoku[i][c] == key){
            res = true;
            break;
        }
    }
    if(sudoku[(r%3+1)%3 + r/3*3][(c%3+1)%3 + c/3*3] == key
    || sudoku[(r%3+1)%3 + r/3*3][(c%3+2)%3 + c/3*3] == key
    || sudoku[(r%3+2)%3 + r/3*3][(c%3+1)%3 + c/3*3] == key
    || sudoku[(r%3+2)%3 + r/3*3][(c%3+2)%3 + c/3*3] == key){
        res = true;
    } 

    return res;
}

bool dfs(int sudoku[][10], int cnt){
    if(cnt == 81){
        return true;
    }

    int r = cnt/9, c = cnt%9;
    if(sudoku[r][c] != 0){
        if(dfs(sudoku, cnt + 1)){
            return true;
        }
    }
    else{
        for(int i = 1; i <= 9; i++){
            if(!lineCheck(sudoku, r, c, i)){
                sudoku[r][c] = i;
                if(dfs(sudoku, cnt + 1)){
                    return true;
                }
                sudoku[r][c] = 0;
            }
        }
    }

    return false;
}

int main(){
    int sudoku[10][10] = {0};
    int temp;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> temp;
            sudoku[i][j] = temp;
        }
    }

    dfs(sudoku, 0);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << sudoku[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}