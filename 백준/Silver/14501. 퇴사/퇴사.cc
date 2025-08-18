#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> t(n+1), p(n+1), dp(n+2, 0);

    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }

    for (int i = n; i >= 1; i--) {
        if (i + t[i] <= n + 1) {
            dp[i] = max(dp[i+1], p[i] + dp[i+t[i]]);
        } else {
            dp[i] = dp[i+1];
        }
    }

    cout << dp[1] << "\n";
}
