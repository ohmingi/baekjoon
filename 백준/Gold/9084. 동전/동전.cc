#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
vector<int> dp;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n,k;
        cin >> n;

        v.assign(n+1,0);

        for(int i = 1; i <= n; i++){
            cin >> v[i];
        }

        cin >> k;
        dp.assign(k+1,0);

        dp[0] = 1;

        for(int i = 1; i <= n; i++){
            for(int t = v[i]; t <= k; t++){
                dp[t] += dp[t - v[i]];
            }
        }
    
        cout << dp[k] << "\n";
    }
}