#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int t;
    int x1, y1, r1, x2, y2, r2;
    float dist;

    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> x1 >> y1 >> r1;
        cin >> x2 >> y2 >> r2;

        dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        if(dist == 0 && r1 == r2){
            cout << -1 << '\n';
        }
        else if(dist + min(r1, r2) < max(r1, r2)){
            cout << 0 << '\n';
        }
        else if(dist > r1 + r2){
            cout << 0 << '\n';
        }
        else if(dist == r1 + r2 || dist == max(r1, r2) - min(r1, r2)){
            cout << 1 << '\n';
        }
        else{
            cout << 2 << '\n';
        }
    }

    return 0;
}