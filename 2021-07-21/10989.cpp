#include <iostream>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int arr[10001] = {0};

    cin >> n;
    int t;
    for(int i = 0; i < n; i++){
        cin >> t;
        arr[t]++;
    }

    for(int i = 1; i <= 10000; i++){
        for(int j = 0; j < arr[i]; j++){
            cout << i << '\n';
        }
    }


    return 0;
}