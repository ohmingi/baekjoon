#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> q;
    
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        q.push(a);
    }

    if(q.size() == 1){
        cout << 0;
        return 0;
    }

    int cnt = 0;

    while(q.size() > 1){
        int a,b;
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();
        cnt += a + b;
        q.push(a + b);
    }

    cout << cnt;
}