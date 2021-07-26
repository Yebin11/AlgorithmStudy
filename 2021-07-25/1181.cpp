#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string a, string b){
    int l1 = a.length();
    int l2 = b.length();

    if(l1 == l2){
        return a < b;
    }
    else{
        return l1 < l2;
    }
}

int main(){
    int n;
    string words[20001];
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> words[i];
        for(int j = 0; j < i; j++){
            if(words[i] == words[j]){
                i--;
                n--;
                break;
            }
        }
    }

    sort(words, words + n, compare);

    for(int i = 0; i < n; i++){
        cout << words[i] << '\n';
    }

    return 0;
}