#include <iostream>

using namespace std;

int main(){
    int n;
    int nums[100001];
    int dp[100001];
    int res;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    dp[0] = nums[0];
    res = dp[0];
    for(int i = 1; i < n; i++){
        dp[i] = nums[i];
        if(dp[i-1] > 0)
            dp[i] += dp[i-1];
        res = max(res, dp[i]);
    }

    cout << res;

    return 0;
}