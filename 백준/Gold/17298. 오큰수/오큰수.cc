#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> answer(n, -1); 
    stack<int> s;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    
    for (int i = n - 1; i >= 0; i--) {
        
        while (!s.empty() && s.top() <= v[i]) {
            s.pop();
        }

        
        if (!s.empty()) {
            answer[i] = s.top();
        }

        
        s.push(v[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }
}
