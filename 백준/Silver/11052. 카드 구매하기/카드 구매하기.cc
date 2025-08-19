#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long long> v(n+1);
    vector<long long> dp(n+1);

    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }

    dp[1] = v[1];
    
    for(int i = 2; i <= n; i++){
        for(int t = 1; t <= i; t++){
            dp[i] = max(dp[i - t] + v[t], dp[i]);
        }
    }

    cout << dp[n];

}