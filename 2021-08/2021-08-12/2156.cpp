#include <iostream>

using namespace std;

int main(){
    int n;
    int wine[10001];
    int dp[10001] = {0};

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> wine[i];
    }

    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];
    dp[3] = wine[2] + wine[3];

    for(int i = 3; i <= n; i++){
        dp[i] = max(dp[i-3] + wine[i] + wine[i-1], dp[i-2] + wine[i]);
        dp[i] = max(dp[i-1], dp[i]);
    }

    cout << dp[n];

    return 0;
}