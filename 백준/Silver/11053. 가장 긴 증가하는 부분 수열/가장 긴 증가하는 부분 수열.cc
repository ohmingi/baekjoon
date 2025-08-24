#include <iostream>
#include <vector>

using namespace std;

int main(){
    int a;
    cin >> a;

    vector<int> v(a + 1,1);
    vector<int> arr(a+1);

    for(int i = 1; i <= a; i++){
        cin >> arr[i];
    }   

    v[1] = 1;
    
    for(int i = 2; i <= a; i++){
        for(int t = 1; t < i; t++){
            if(arr[i] > arr[t]){
                v[i] = max(v[i], v[t] + 1);
            }
        }
    }

    int c = 0;  

    for(int i = 1; i <= a; i++){
        c = max(c, v[i]);
    }

    cout << c;
}