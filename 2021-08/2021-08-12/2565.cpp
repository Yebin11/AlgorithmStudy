#include <iostream>
#include <algorithm>

using namespace std;

struct line{
    int s;
    int e;
};

bool lineCmp(line a, line b){
    return a.s < b.s;
}

int main(){
    int n;
    line lines[101];

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> lines[i].s >> lines[i].e;
    
    sort(lines, lines + n, lineCmp);

    int dp[101];
    for(int i = 0; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(lines[i].e > lines[j].e){
                if(dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, dp[i]);
    }
    cout << n - ans;

    return 0;
}