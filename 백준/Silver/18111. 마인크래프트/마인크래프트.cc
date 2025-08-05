#include <iostream>
#include <vector>

using namespace std;

int arr[250001];

int main(){
    int n,m,b;
    int sec = 0;
    int height;
    int msec = 1e9;

    cin >> n >> m >> b;

    for(int i = 0; i < n*m; i++){
        cin >> arr[i];
    }

    for(int i = 0; i <= 256; i++){
        sec = 0;
        int b1 = b;

        for(int t = 0; t < n*m; t++){
            if(arr[t] > i){
                sec += 2*(arr[t] - i);
                b1 += (arr[t] - i);
            }
            if(arr[t] < i){
                sec += (i - arr[t]);
                b1 -= i - arr[t];
            }
        }

        if(b1 >= 0){
            if(msec >= sec){
                msec = sec;
                height = i;
            }
        }
    }

    cout << msec << " " << height;
}