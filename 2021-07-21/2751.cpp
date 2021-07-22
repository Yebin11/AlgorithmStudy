#include <iostream>
using namespace std;

int arr[1000000];
int temp[1000000];

void merge(int left, int middle, int right){
    int i = left;
    int j = middle + 1;
    int k = left;

    while(i <= middle && j <= right){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }

    if(i > middle){
        for(int l = j; l <= right; l++){
            temp[k++] = arr[l];
        }
    }
    else{
        for(int l = i; l <= middle; l++){
            temp[k++] = arr[l];
        }
    }

    for(int l = left; l <= right; l++){
        arr[l] = temp[l];
    }
}

void mergeSort(int left, int right){
    if(left < right){
        int middle = (left + right) / 2;
        mergeSort(left, middle);
        mergeSort(middle + 1, right);
        merge(left, middle, right);
    }
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    mergeSort(0, n - 1);

    for(int i = 0; i < n; i++){
        cout << arr[i] << '\n';
    }

    return 0;
}