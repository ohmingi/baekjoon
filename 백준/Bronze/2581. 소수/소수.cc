#include <iostream>

using namespace std;

int main(){
    int m,n;
    cin >> m >> n;

    int sum = 0;
    int mi = 1e9;
    
    if(m == 1){
        for(int i = 2; i <= n; i++){
            bool b = 1;
            for(int t = 2; t < i; t++){
                if(i % t == 0) {
                    b = 0;
                    break;
                }
            }
            if(b == 1){
                sum += i;
                mi = min(mi, i);
            }
        }
    }
    else{
        for(int i = m; i <= n; i++){
            bool b = 1;
            for(int t = 2; t < i; t++){
                if(i % t == 0) {
                    b = 0;
                    break;
                }
            }
            if(b == 1){
                sum += i;
                mi = min(mi, i);
            }
        }
    }

    if(sum == 0){
        cout << -1;
        return 0;
    }

    cout << sum << "\n" << mi;

}