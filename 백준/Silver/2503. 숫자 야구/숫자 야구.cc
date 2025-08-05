#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> v;
vector<pair<int,int>> v1;
int c = 0;
int ch = 0;
bool check;

bool judge(int num, int num1, pair<int, int> p){
    string str= to_string(num);
    string str1= to_string(num1);
    int s = 0;
    int b = 0;

    for(int i = 0; i < 3; i++){
        if(str.find(str1[i]) != string::npos && str[i] != str1[i]){
            b++;
        }
        if(str[i] == str1[i]){
            s++;
        }
    }

    if(s == p.first && b == p.second) return true;
    else{
        return false;
    }
}

bool zero(int num) {
    for (int i = 0; i < 3; i++) {
        if (num % 10 == 0) return true;
        num /= 10;
    }
    return false;
}

bool dup(int num){
    string str = to_string(num);

    if(str[0] == str[1]) return true;
    if(str[1] == str[2]) return true;
    if(str[0] == str[2]) return true;

    return false;
}

int main(){
    int n;
    cin >> n;
    
    v.assign(n, 0);
    v1.assign(n, {0,0});

    for(int i = 0; i < n; i++){
        cin >> v[i] >> v1[i].first >> v1[i].second;        
    }

    for(int i = 123; i <= 987; i++){
        if(zero(i) || dup(i)) continue;
        ch = 0;

        for(int t = 0; t < n; t++){
            if(judge(i, v[t], v1[t])){
                ch++;
            }
        }

        if(ch == n) c++;

    }

    cout << c;
}