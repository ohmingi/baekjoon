#include <iostream>

int N[100001];
int NN[100001];

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;

    cin >> N[1];
    cin >> N[2];

    NN[1] = N[1];
    NN[2] = N[1] + N[2];

    for(int i = 3; i <= n; i++){
        cin >> N[i];
        NN[i] = NN[i-1] + N[i];
    }


    while(m--){
        int i,j;
        cin >> i >> j;

        cout << NN[j] - NN[i - 1] << "\n";
    } 
    
}