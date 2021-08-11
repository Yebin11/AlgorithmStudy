#include <iostream>

using namespace std;

int w[101][101][101];

int wfunc(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0)
        return 1;
    if(a > 20 || b > 20 || c > 20)
        return wfunc(20, 20, 20);

    if(w[a+50][b+50][c+50] != 0)
        return w[a+50][b+50][c+50];
    
    if(a < b && b < c)
        w[a+50][b+50][c+50] = wfunc(a, b, c-1) + wfunc(a, b-1, c-1) - wfunc(a, b-1, c);
    else
        w[a+50][b+50][c+50] = wfunc(a-1, b, c) + wfunc(a-1, b-1, c) + wfunc(a-1, b, c-1) - wfunc(a-1, b-1, c-1);

    return w[a+50][b+50][c+50];
}

int main(){
    int a, b, c;

    cin >> a >> b >> c;
    while(a != -1 || b != -1 || c != -1){
        cout << "w(" << a << ", " << b << ", " << c <<") = " << wfunc(a, b, c) << '\n';
        cin >> a >> b >> c;
    }

    return 0;
}