#include <iostream>

using namespace std;

void dfs(int arr[], bool visited[], int n, int m, int cnt){
    if(cnt == m){
        for(int i = 0; i < m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            visited[i] = true;
            arr[cnt] = i;
            dfs(arr, visited, n, m, cnt + 1);
            visited[i] = false;
        }
    }
}

int main(){
    int n, m;
    int arr[10] = {0};
    bool visited[10] = {0};

    cin >> n >> m;

    dfs(arr, visited, n, m, 0);   

    return 0;
}