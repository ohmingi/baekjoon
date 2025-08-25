#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;

    vector<pair<int,int>> v(n+1);
    vector<vector<int>> dp(n+1, vector<int>(k+1));

    for(int i = 1; i <= n; i++){
        int a,b;
        cin >> a >> b;
        v[i] = {a,b};
    }

    //dp[1][v[1].first] = v[1].second;

    for(int i = 1; i <= n; i++){
        for(int t = 1; t <= k; t++){
            if(v[i].first <= t){
                dp[i][t] = max(dp[i - 1][t], v[i].second + dp[i - 1][t - v[i].first]);
            }
            else{
                dp[i][t] = dp[i - 1][t];
            }
        }
    }

    cout << dp[n][k];
    
}