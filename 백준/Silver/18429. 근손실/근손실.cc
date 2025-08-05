#include <iostream>
#include <vector>

using namespace std;

int n,k;
int c = 0;
int curr = 500;
bool visited[9];
vector<int> v;

void dfs(int dep){
    if(dep == n){
        c++;
        return;
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i] && curr + v[i] - k >= 500){
            curr = curr + v[i] - k;
            visited[i] = 1;
            dfs(dep + 1);
            visited[i] = 0;
            curr = curr - v[i] + k;
        }
    }
}

int main(){
    cin >> n >> k;

    v.assign(n+1, 0);

    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }

    dfs(0);

    cout << c;
}