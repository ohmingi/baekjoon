#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> v(n+1);
    vector<int> dp(k+1, 10001);

    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }

    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        for(int t = v[i]; t <= k; t++){
            dp[t] = min(dp[t], dp[t - v[i]] + 1);
        }
    }

    if(dp[k] == 10001) cout << -1;
    else{
        cout << dp[k];
    }
}