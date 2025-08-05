#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
vector<int> ch;
vector<int> result;
bool visited[401];
int N[4];
int n;
int ma = -1000000001;
int mi = 1000000001;

void cal(){
    int a = v[0];

    for(int i = 0; i < result.size(); i++){
        if(result[i] == -1){
            a = a + v[i+1];
        }
        else if(result[i] == -2){
            a = a - v[i+1];
        }
        else if(result[i] == -3){
            a = a * v[i+1];
        }
        else{
            a = a / v[i+1];
        }
    }

    if(a > ma) ma = a;
    if(a < mi) mi = a;
}

void dfs(int dep){
    if(dep == ch.size()){
        cal();
        return;
    }

    for(int i = 0; i < ch.size(); i++){
        if(!visited[i]){
            visited[i] = 1;
            result.push_back(ch[i]);
            dfs(dep + 1);
            visited[i] = 0;
            result.pop_back();
        }
    }
}

int main(){
    cin >> n;
    v.assign(n, 0);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    for(int i = -1; i >= -4; i--){
        int a;
        cin >> a;
        while(a--){
            ch.push_back(i);
        }
    }

    dfs(0);

    cout << ma << "\n" << mi;
}