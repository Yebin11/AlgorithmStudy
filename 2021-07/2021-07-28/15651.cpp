#include <iostream>

using namespace std;

void dfs(int arr[], int n, int m, int cnt){
    if(cnt == m){
        for(int i = 0; i < m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++){
        arr[cnt] = i;
        dfs(arr, n, m, cnt + 1);
    }
}

int main(){
    int n, m;
    int arr[10] = {0};

    cin >> n >> m;

    dfs(arr, n, m, 0);

    return 0;
}