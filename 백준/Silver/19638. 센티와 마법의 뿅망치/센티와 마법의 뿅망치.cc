#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n, h, t;
    cin >> n >> h >> t;

    priority_queue<int> pq;

    while(n--){
        int a;
        cin >> a;
        
        pq.push(a);
    }

    int count = 0;

    if(pq.top() < h){
            cout << "YES\n" << 0;
            return 0;
    }

    for(int i = 0; i < t; i++){
        int a = pq.top();
        if(pq.top() == 1) break;
        a = a/2;
        pq.pop();
        pq.push(a);
        count++;

        if(pq.top() < h){
            cout << "YES\n" << count;
            return 0;
        }
    }

    cout << "NO\n" << pq.top();
}