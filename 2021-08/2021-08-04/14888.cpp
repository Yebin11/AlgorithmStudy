#include <iostream>

using namespace std;

int mymin = 1000000001;
int mymax = -1000000001;
void dfs(int n, int nums[], int ops[], int cnt, int res){
    if(cnt == n){
        if(res > mymax) mymax = res;
        if(res < mymin) mymin = res;
        return;
    }
    for(int i = 0; i < 4; i++){
        if(ops[i] > 0){
            ops[i]--;
            if(i == 0)
                dfs(n, nums, ops, cnt + 1, res + nums[cnt]);
            else if(i == 1)
                dfs(n, nums, ops, cnt + 1, res - nums[cnt]);
            else if(i == 2)
                dfs(n, nums, ops, cnt + 1, res * nums[cnt]);
            else if(i == 3)
                dfs(n, nums, ops, cnt + 1, res / nums[cnt]); 
            ops[i]++;   
        }
    }
    return;
}

int main(){
    int n;
    int nums[15];
    int ops[4];

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    for(int i = 0; i < 4; i++){
        cin >> ops[i];
    }

    dfs(n, nums, ops, 1, nums[0]);
    cout << mymax << '\n' << mymin;


    return 0;
}