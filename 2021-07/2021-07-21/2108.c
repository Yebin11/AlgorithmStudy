#include <stdio.h>
#include <math.h>

int main(){
    int n;
    int sum = 0;
    int arr[500000];
    int cnt[8002] = {0};

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
        cnt[arr[i] + 4000]++;
    }

    int t = 0;
    for(int i = 0; i <= 8000; i++){
        for(int j = 0; j < cnt[i]; j++){
            arr[t++] = i - 4000;
        }
    }

    printf("%.0lf\n", round((double)sum / (double)n));

    printf("%d\n", arr[n/2]);

    int max_cnt = 0;
    int res;
    int flag = 0;
    for(int i = 0; i <= 8000; i++){
        if(max_cnt < cnt[i]){
            max_cnt = cnt[i];
            res = i - 4000;
            flag = 0;
        }
        else if(max_cnt == cnt[i]){
            flag = 1;
        }
    }
    if(flag == 1){
        int c = 0;
        for(int i = 0; i <= 8000; i++){
            if(cnt[i] == max_cnt){
                c++;
                if(c == 2){
                    res = i - 4000;
                    break;
                }
            }
        }
    }
    printf("%d\n", res);

    printf("%d", arr[n-1] - arr[0]);

    return 0;
}