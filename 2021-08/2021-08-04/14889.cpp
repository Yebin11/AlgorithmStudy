#include <iostream>

using namespace std;

int mymin = 1 << 30;

void dfs(int n, int s[][21], bool visited[], int cnt, int cur){
    if(cnt == n/2){
        int t1 = 0, t2 = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(visited[i] && visited[j]){
                    t1 += s[i][j] + s[j][i];
                }
                else if(!visited[i] && !visited[j]){
                    t2 += s[i][j] + s[j][i];
                }
            }
        }
        if(mymin > abs(t1 - t2)){
            mymin = abs(t1 - t2);
        }
    }
    for(int i = 0; i < n; i++){
        if(visited[i] == false && i > cur){
            visited[i] = true;
            dfs(n, s, visited, cnt + 1, i);
            visited[i] = false;
        }
    }
}

int main(){
    int n;
    int s[21][21];
    bool visited[20];

    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> s[i][j];

    dfs(n, s, visited, 0, -1);
    cout << mymin;

    return 0;
}