#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<long long>> dp(n+1, vector<long long>(10));

    dp[1][0] = 0;

    for(int i = 1; i <= 9; i++){
        dp[1][i]++;
    }

    for(int i = 2; i <= n; i++){
        for(int t = 0; t <= 9; t++){
            if(t == 0){
                dp[i][t] = (dp[i - 1][t + 1]) % 1000000000;
            }
            else if(t == 9){
                 dp[i][t] = (dp[i - 1][t - 1]) % 1000000000;
            }
            else{
                 dp[i][t] = (dp[i - 1][t - 1] + dp[i - 1][t + 1]) % 1000000000;
            }
        }
    }

    long long c = 0;

    for(int i = 0; i <= 9; i++){
        c = (c + dp[n][i]) % 1000000000;
    }
    
    cout << c;


}