#include <iostream>

using namespace std;

int up(int n, int stairs[], int dp[]){
    if(n <= 3)
        return dp[n];
    if(dp[n] != 0)
        return dp[n];
    return dp[n] = max(up(n-2, stairs, dp), up(n-3, stairs, dp) + stairs[n-1]) + stairs[n];
}

int main(){
    int n;
    int stairs[301];
    int dp[301] = {0};

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> stairs[i];
    }

    dp[0] = stairs[0];
    dp[1] = stairs[0] + stairs[1];
    dp[2] = max(stairs[0], stairs[1]) + stairs[2];
    dp[3] = max(dp[1], dp[0] + stairs[2]) + stairs[3];

    up(n-1, stairs, dp);

    cout << dp[n-1];

    return 0;
}