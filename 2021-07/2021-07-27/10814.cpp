#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct member{
    int age;
    string name;
};

member members[100000];

bool cmp(member a, member b){
    return a.age < b.age;
}

int main(){
    int n;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> members[i].age >> members[i].name;
    }

    stable_sort(members, members + n, cmp);

    for(int i = 0; i < n; i++){
        cout << members[i].age << ' ' << members[i].name << '\n';
    }

    return 0;
}