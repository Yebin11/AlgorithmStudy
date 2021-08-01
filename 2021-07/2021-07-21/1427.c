#include<stdio.h>

int main(){
    long long int n;
    int arr[11] = {0};
    int l = 0;

    scanf("%lld", &n);

    for(int i = 0; n > 0; i++, n /= 10){
        arr[i] = n % 10;
        l++;
    }

    for(int i = 1; i < l; i++){
        int key = arr[i];
        int j;
        for(j = i - 1; j >= 0 && arr[j] < key; j--){
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }

    for(int i = 0; i < l; i++){
        printf("%d", arr[i]);
    }

    return 0;
}