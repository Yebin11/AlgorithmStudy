#include <iostream>

using namespace std;

struct nums{
    int zero;
    int one;
};

void fibo(nums dp[]){
    dp[0].zero = 1;
    dp[0].one = 0;
    dp[1].zero = 0;
    dp[1].one = 1;

    for(int i = 2; i <= 40; i++){
        dp[i].zero = dp[i-1].zero + dp[i-2].zero;
        dp[i].one = dp[i-1].one + dp[i-2].one;
    }
}

int main(){
    int t;
    nums dp[41];
    cin >> t;

    fibo(dp);

    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        cout << dp[n].zero << ' ' << dp[n].one << '\n';
    }

    return 0;
}