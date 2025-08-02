#include <iostream>

int col[15];
int N;
int Count = 0;

using namespace std;

bool check(int x,int y){
    for(int i = 0; i < x; i++){
        if(col[i] == y) return false;
        if(abs(col[i]-y) == abs(i-x)) return false;
    }

    return true;
}

void dfs(int x){
    if(x == N){
        Count++;
    }
    

    for(int i = 0; i < N; i++){
        if(check(x,i)){
            col[x] = i;
            dfs(x+1);
        }
    }
}

int main(){
    cin >> N;

    dfs(0);

    cout << Count;
}