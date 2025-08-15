#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int a;
        cin >> a;

        vector<int> dp(a+1);

        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;

        for(int i = 4; i <= a; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        cout << dp[a] << "\n";
    }
}