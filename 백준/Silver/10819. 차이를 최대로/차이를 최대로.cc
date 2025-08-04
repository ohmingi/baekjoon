#include <iostream>
#include <vector>

using namespace std;

int Max = 0;
int n;
int N[9];
vector<int> sequence;
bool visited[9];

void sum(vector<int> v){
    int a = 0;

    for(int i = 0; i <= n-2; i++){
        a += abs(v[i] - v[i+1]);

    }

    if(a > Max) Max = a;
}

void dfs(int dep){
    if(dep == n){
        sum(sequence);
        return;
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            visited[i] = true;
            sequence.push_back(N[i]);
            dfs(dep + 1);
            sequence.pop_back();
            visited[i] = false;
        }
    }
}

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> N[i];
    }

    dfs(0);
    cout << Max;
}