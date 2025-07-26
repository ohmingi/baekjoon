#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, P;
    int count = 0;

    cin >> n >> P;

    vector<int> st[P + 1];

    while (n--) {
        int j, p;
        cin >> j >> p;

        vector<int> &current_stack = st[j];

        while (!current_stack.empty() && current_stack.back() > p) {
            count++;
            current_stack.pop_back();
        }

        if (current_stack.empty() || current_stack.back() != p) {
            current_stack.push_back(p);
            count++;
        }
    }

    cout << count << "\n";
}
