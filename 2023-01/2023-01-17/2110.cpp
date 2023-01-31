#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, c;
    int x[200001] = {0};
    int start, end, mid, answer;
    
    cin >> n >> c;
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }

    sort(x, x + n);

    start = 1;
    end = x[n-1] - x[0];
    answer = 1;
    while(start <= end){
        int count = 1;
        int current = x[0];
        mid = (start + end) / 2;
        for(int i = 1; i < n; i++){
            if(x[i] >= current + mid){
                count += 1;
                current = x[i];
            }
        }
        if(count >= c){
            start = mid + 1;
            answer = mid;
        }
        else{
            end = mid - 1;
        }
    }   

    cout << answer;

    return 0;
}