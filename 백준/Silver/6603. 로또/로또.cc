#include <iostream>
#include <vector>

using namespace std;

int k;
vector<int> v;
int n[13];

void dfs(int s,int dep){
    if(dep == 6){
        for(int a : v){
            cout << a << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = s; i < k; i++){
        v.push_back(n[i]);
        dfs(i + 1, dep + 1);
        v.pop_back();
    }
}

int main(){    
    while(cin >> k){
        if(k == 0) return 0;

        v.clear();

        for(int i = 0; i < k; i++){
            cin >> n[i];
        }

        dfs(0,0);
        cout << "\n";
    }
}