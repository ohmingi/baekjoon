#include <iostream>
#include <cmath>

using namespace std;

bool dec(int a){
    if(a == 2) return true;
    
    for(int i = 2; i <= sqrt(a); i++){
        if(a % i == 0){
            return false;
        }
    }

    return true;
}

int main(){
    int n;
    cin >> n;

    int arr[2];

    while(n--){
        int a;
        cin >> a;

        for(int i = 2; i <= a/2; i++){
            if(dec(i) && dec(a-i)){
                arr[0] = i;
                arr[1] = a - i;
            }
        }

        cout << arr[0] << " " << arr[1] << "\n";
    }
}