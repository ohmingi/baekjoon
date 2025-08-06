#include <iostream>
#include <vector>

using namespace std;

vector<int> v(11);
int n[11][11];
int check[11];
int ma = -1;

void dfs(int dep){
    if(dep == 11){
        int a = 0;
        for(auto c : v){
            a += c;
        }

        if(a > ma) ma = a;
    }

    for(int i = 0; i < 11; i++){
        if(check[i] == 0 &&  n[i][dep] != 0){
            v.push_back(n[i][dep]);
            check[i] = 1;
            dfs(dep + 1);
            check[i] = 0;
            v.pop_back();
        }
    }
}

int main(){
    int c;
    cin >> c;

    while(c--){
        n[11][11] = {0};
        check[11] = {0};
        ma = -1;
        v.clear();

        for(int i = 0; i < 11; i++){
            for(int t = 0; t < 11; t++){
                cin >> n[i][t];
            }
        }

        dfs(0);

        cout << ma <<"\n";
    }
}