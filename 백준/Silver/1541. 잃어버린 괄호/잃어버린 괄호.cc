#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

int main() {
  string s;
  cin >> s;

  stack<char> st;

  for (int i = 0; i < s.length(); i++) {
      st.push(s[i]);
  }

  int result = 0;
  int total = 0;

  while (!st.empty()) {
    if (st.top() <= '9' && st.top() >= '0') {
      int cnt = 0;
      int t = 0;
      while (!st.empty() && (st.top() <= '9' && st.top() >= '0')) {
        int tp = st.top() - '0';
        t += tp * (pow(10,cnt));
        cnt++;
        st.pop();
      }
      total += t;
    }
    else if (st.top() == '+') {
      st.pop();
    }
    else {
      st.pop();
      result -= total;
      total = 0;
    }
  }


  if (total > 0) {
    result += total;
  }

  cout << result;
}