#include <iostream>

using namespace std;

int arr[1001];
int dp[1001];
int rdp[1001];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i]; 
    }

    for(int i = 1; i <= n; i++){
        dp[i] = 1;
        for(int j = 1; j <= i; j++){
            if(arr[j] < arr[i] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
            }
        }
    }

    for(int i = n; i >= 1; i--){
        rdp[i] = 1;
        for(int j = n; j >= i; j--){
            if(arr[j] < arr[i] && rdp[i] < rdp[j] + 1){
                rdp[i] = rdp[j] + 1;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= n; i++){
        if(ans < dp[i] + rdp[i] - 1){
            ans = dp[i] + rdp[i] - 1;
        }
    }
    cout << ans;

    return 0;
}