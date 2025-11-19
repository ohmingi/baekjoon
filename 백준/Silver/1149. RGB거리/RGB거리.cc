#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int Min = 1e9;
vector<int> v[3];

void dfs(int x, int cnt, int ex) {
  if (x == n + 1) {
    if (Min > cnt) Min = cnt;
    return;
  }

  for (int i = 0; i < 3; i++) {
    if (i != ex) {
      cnt += v[i][x];
      dfs(x+1, cnt, i);
      cnt -= v[i][x];
    }
  }
}

int main() {
  cin >> n;

  int dp[1001][3];

  for (int i = 1; i <= n; i++) {
    int r,g,b;
    cin >> r >> g >> b;
    dp[i][0] = r;
    dp[i][1] = g;
    dp[i][2] = b;
  }

  for (int i = 2; i <= n; i++) {
    for (int t = 0; t < 3; t++) {
      if (t == 0) {
        dp[i][t] = min(dp[i-1][1], dp[i-1][2]) + dp[i][t];
      }
      if (t == 1) {
        dp[i][t] = min(dp[i-1][0], dp[i-1][2]) + dp[i][t];
      }
      if (t == 2) {
        dp[i][t] = min(dp[i-1][0], dp[i-1][1]) + dp[i][t];
      }
    }
  }

  //dfs(1,0,-1);

  //cout << Min << endl;

  int result = min(min(dp[n][0], dp[n][1]), dp[n][2]);
  cout << result;
}