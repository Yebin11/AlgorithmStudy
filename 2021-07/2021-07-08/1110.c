#include <stdio.h>

int main(){
    int n;
    int a, b, c;
    int cnt = 0;

    scanf("%d", &n);
    
    c = n;
    while(1){
        cnt++;
        if(c < 10){
            a = 0;
            b = c;
        }
        else{
            a = c / 10; 
            b = c % 10;
        }
        c = b * 10 + (a + b) % 10;
        if(c == n) break;
    }

    printf("%d", cnt);

    return 0;
}