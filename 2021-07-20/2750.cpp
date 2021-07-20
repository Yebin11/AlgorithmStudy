#include<iostream>
using namespace std;

int main(){
    int n;
    int arr[1000] = { 0, };
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j;
        for(j = i -1; j >= 0 && arr[j] > key; j--){
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }

    for(int i = 0; i < n; i++){
        cout << arr[i] << '\n';
    }

    return 0;
}