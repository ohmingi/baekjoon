#include <iostream>

using namespace std;

int main(){
    int a,b;
    cin >> a >> b;

    int aa = a;
    int bb = b;

    while(b != 0){
        int c = b;
        b = a % b;
        a = c;
    }

    cout << a << "\n" << aa*bb / a;
}