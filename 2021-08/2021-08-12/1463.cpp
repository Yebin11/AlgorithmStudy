#include <iostream>

using namespace std;

void makeOne(int n, int *dp){
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for(int i = 4; i <= n; i++){
        if(i % 3 == 0 && i % 2 == 0){
            dp[i] = min(dp[i/3], min(dp[i-1], dp[i/2])) + 1;
        }
        else if(i % 3 == 0){
            dp[i] = min(dp[i/3], dp[i-1]) + 1;
        }
        else if(i % 2 == 0){
            dp[i] = min(dp[i/2], dp[i-1]) + 1;
        }
        else{
            dp[i] = dp[i-1] + 1;
        }
    }
}

int main(){
    int n;
    int *dp = new int[1000001];
    
    cin >> n;

    makeOne(n, dp);
    cout << dp[n];

    delete[] dp;

    return 0;
}