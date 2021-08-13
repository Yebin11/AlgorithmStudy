#include <iostream>
#include <algorithm>

using namespace std;

struct meeting{
    int s;
    int e;
};

bool cmp(meeting a, meeting b){
    if(a.e == b.e)
        return a.s < b.s;
    return a.e < b.e;
}

int main(){
    int n;
    meeting times[100001];

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> times[i].s >> times[i].e;

    sort(times, times + n, cmp);

    int now = times[0].e;
    int cnt = 1;
    for(int i = 1; i < n; i++){
        if(now <= times[i].s){
            cnt++;
            now = times[i].e;
        }
    }

    cout << cnt;

    return 0;
}