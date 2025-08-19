#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> dp(n+1);

    if(n >= 1) dp[1] = 1;
    if(n >= 2) dp[2] = 2;
    if(n >= 3) dp[3] = 3;

    for(int i = 4; i <= n; i++){
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }

    cout << dp[n];
}