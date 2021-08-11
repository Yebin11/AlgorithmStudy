#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    int *tiles = new int[1000001];

    tiles[1] = 1;
    tiles[2] = 2;

    for(int i = 3; i <= n; i++){
        tiles[i] = (tiles[i-1] + tiles[i-2]) % 15746;
    }
    cout << tiles[n];


    delete[] tiles;
    return 0;
}