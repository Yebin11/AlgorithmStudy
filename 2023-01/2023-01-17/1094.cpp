#include <iostream>

using namespace std;

int main(){
    int x;
    int length = 64;
    int shortest = length;
    int count = 1;

    cin >> x;

    while(length != x){
        if(length - shortest / 2 >= x){
            length -= shortest / 2;
        }
        else{
            count++;
        }
        shortest /= 2;
    }

    cout << count;

    return 0;
}