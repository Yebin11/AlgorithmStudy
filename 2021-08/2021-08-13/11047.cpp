#include <iostream>

using namespace std;

int main(){
    int n, k;
    int res = 0;
    int v[11];

    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> v[i];

    for(int i = n-1; i >= 0; i--){
        if(v[i] <= k){
            res += k / v[i];
            k %= v[i];
        }
    }

    cout << res;

    return 0;
}