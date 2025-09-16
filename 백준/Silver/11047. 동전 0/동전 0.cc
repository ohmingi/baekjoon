#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;

    vector<int> v(n+1);

    for(int i = 1; i < n + 1; i++){
        cin >> v[i];
    }

    int c = 0;

    for(int i = n; i >= 1; i--){
        if(k == 0) break;
        if(k >= v[i]){
            while(k >= v[i]){
                c++;
                k -= v[i];
            }
        }
    }

    cout << c;
}