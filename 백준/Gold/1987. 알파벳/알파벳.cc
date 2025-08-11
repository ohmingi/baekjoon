#include <iostream>
#include <algorithm>

using namespace std;

int r, c;
char ch[21][21];
int cnt = 1;
bool used[26]; // 알파벳 사용 여부 배열

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool check(int x, int y) {
    return x > 0 && x <= r && y > 0 && y <= c;
}

void dfs(int x, int y, int depth) {
    cnt = max(cnt, depth);

    for (int i = 0; i < 4; i++) {
        int newx = x + dx[i];
        int newy = y + dy[i];
        
        if (check(newx, newy)) {
            int idx = ch[newx][newy] - 'A';
            if (!used[idx]) {
                used[idx] = true;
                dfs(newx, newy, depth + 1);
                used[idx] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        string str;
        cin >> str;
        for (int t = 1; t <= c; t++) {
            ch[i][t] = str[t - 1];
        }
    }

    used[ch[1][1] - 'A'] = true;
    dfs(1, 1, 1);

    cout << cnt;
}
