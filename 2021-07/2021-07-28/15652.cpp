#include <iostream>

using namespace std;

void dfs(int arr[], int n, int m, int cnt){
    if(cnt - 1 == m){
        for(int i = 1; i <= m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++){
        if(arr[cnt - 1] <= i){
            arr[cnt] = i;
            dfs(arr, n, m, cnt + 1);
        }
    }
}

int main(){
    int n, m;
    int arr[10] = {0};

    cin >> n >> m;

    dfs(arr, n, m, 1);

    return 0;
}