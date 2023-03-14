#include <iostream>
using namespace std;

class stack {
private:
    int datasize = 0;
    
    int arr[100000] = {};
public:
    
    bool empty() {
        return datasize == 0;
    }
    int top() {
        if (empty()) return -1;
        return arr[datasize - 1];
    }
    void push(int x) {
        arr[datasize++] = x;
    }
    void pop() {
        if (datasize == 0) {
            cout << -1 << '\n';
            return;
        }
        cout << top() << '\n';
        datasize--;
    }

    void size() {
        cout << datasize << "\n";
    }
};

int main() {
    int t, n;
    cin >> n;
    string init;
    stack s;

    while (n--) {
        cin >> init;
        if (init == "empty") {
            cout << s.empty() << '\n';
        }
        else if (init == "top") {
            cout << s.top() << '\n';
        }
        else if (init == "pop") {
            s.pop();
        }
        else if (init=="size") {
            s.size();
        }
        else {
            int x;
            cin >> x;
            s.push(x);
        }
    }
}