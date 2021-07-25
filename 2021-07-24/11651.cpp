#include <iostream>
using namespace std;

struct point{
    int x;
    int y;
};

point temp[100000];

void merge(point arr[], int left, int mid, int right){
    int i, j, k;
    i = left;
    j = mid + 1;
    k = left;

    while(i <= mid && j <= right){
        if((arr[i].y < arr[j].y) || (arr[i].y == arr[j].y && arr[i].x < arr[j].x)){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }

    if(i <= mid){
        for(int l = i; l <= mid; l++){
            temp[k++] = arr[l];
        }
    }
    else{
        for(int l = j; l <= right; l++){
            temp[k++] = arr[l];
        }
    }

    for(int l = left; l <= right; l++){
        arr[l] = temp[l];
    }
}

void mergeSort(point arr[], int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main(){
    int n;
    point points[100000];
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> points[i].x >> points[i].y;
    }

    mergeSort(points, 0, n - 1);
    
    for(int i = 0; i < n; i++){
        cout << points[i].x << " " << points[i].y << '\n';
    }

    return 0;
}