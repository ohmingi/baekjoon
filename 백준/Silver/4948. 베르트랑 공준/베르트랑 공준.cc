#include <iostream>
#define maxx 123456*2

using namespace std;

bool arr[maxx + 1];

void prime(){
    arr[0] = arr[1] = true;

    for(int i = 2; i*i <= maxx; i++){
        if(arr[i] == false){
            for(int t = i*i; t <= maxx; t += i){
                arr[t] = true;
            }
        }
    }
}

int main(){
    prime();

    while(true){
        int n;
        cin >> n;

        if(n == 0) return 0;

        int cnt = 0;
        for(int i = n+1; i <= n*2; i++){
            if(!arr[i]){
                cnt++;
            }
        }

        cout << cnt << "\n";
    }
}