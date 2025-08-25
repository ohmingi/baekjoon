#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<vector<int>> v(n+1, vector<int>(n+1));
    vector<vector<int>> dp(n+1, vector<int>(n+1));

    for(int i = 1; i <= n; i++){
        for(int t = 1; t <= i; t++){
            cin >> v[i][t];
        }
    }

    dp[1][1] = v[1][1];

    for(int i = 2; i <= n; i++){
        for(int t = 1; t <= i; t++){
            dp[i][t] = max(dp[i - 1][t - 1] + v[i][t], dp[i - 1][t] + v[i][t]);
        }
    }

    int aa = 0;

    for(auto a : dp[n]){
        aa = max(aa, a);
    }

    cout << aa;

}