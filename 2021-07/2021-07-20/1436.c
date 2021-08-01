#include <stdio.h>

int isIt666(int n){
    int res = 0;
    int flag = 0;
    int cnt = 0;

    for(; n > 0; n /= 10){
        if(flag == 1 && n % 10 == 6){
            cnt++;
            if(cnt == 3) break;
        }
        else if(n % 10 == 6){
            flag = 1;
            cnt = 1;
        }
        else if(flag == 1){
            flag = 0;
            cnt = 0;
        }
    }

    if(cnt == 3) res = 1;

    return res;
}

int main(){
    int n;
    int cnt = 0;

    scanf("%d", &n);

    for(int i = 666; ; i++){
        if(isIt666(i) == 1){
            cnt++;
        }
        if(cnt == n){
            printf("%d", i);
            break;
        }
    }

    return 0;
}