#include <iostream>

using namespace std;

int tri[500][501];
int dp[500][501];

void triangle(int n){
    dp[0][0] = tri[0][0];
    dp[1][0] = dp[0][0] + tri[1][0];
    dp[1][1] = dp[0][0] + tri[1][1];

    for(int i = 2; i < n; i++){
        for(int j = 0; j < i+1; j++){
            if(j > 0 && j < i){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + tri[i][j];
            }
            else if(j == 0){
                dp[i][j] = dp[i-1][j] + tri[i][j];
            }
            else{
                dp[i][j] = dp[i-1][j-1] + tri[i][j];
            }
        }
    }
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i+1; j++){
            cin >> tri[i][j];
        }
    }

    triangle(n);

    int res = 0;
    for(int i = 0; i < n; i++)
        res = max(res, dp[n-1][i]);

    cout << res;

    return 0;
}