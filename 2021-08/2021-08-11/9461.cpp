#include <iostream>

using namespace std;

void sequence(long long dp[]){
    dp[0] = dp[1] = dp[2] = 1;
    dp[3] = dp[4] = 2;
    for(int i = 5; i < 101; i++){
        dp[i] = dp[i-2] + dp[i-3];
    }
}

int main(){
    int t;
    cin >> t;
    long long dp[101];
    sequence(dp);

    for(int i = 0; i < t; i++){
        int n; 
        cin >> n;
        cout << dp[n-1] << '\n';
    }

    return 0;
}