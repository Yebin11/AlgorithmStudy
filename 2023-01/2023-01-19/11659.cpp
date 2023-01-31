#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int num[100001] = {0};
    int n, m;
    int t, s, e;

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >> t;
        num[i] = num[i-1] + t;
    }

    for(int i = 0; i < m; i++){
        cin >> s >> e;
        cout << num[e] - num[s - 1] << '\n';
    }

    return 0;
}