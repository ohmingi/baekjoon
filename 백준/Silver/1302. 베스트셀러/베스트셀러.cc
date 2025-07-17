#include <iostream>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;
    int max = 0;

    string resul;

    map<string,int> m;

    while(n--){
        string str;
        cin >> str;
        m[str]++;
    }

    for (auto a : m) {
        if(a.second > max){
            resul = a.first;
            max = a.second;
        }
    }

    cout << resul;
}