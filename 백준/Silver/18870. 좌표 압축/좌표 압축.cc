#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> v;
  vector<int> v1;
  map<int,int> m;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (m.find(a) == m.end()) {
      v.push_back(a);
    }
    v1.push_back(a);
    m[a] = 1;
  }

  sort(v.begin(), v.end());

  for (int i = 0; i < v.size(); i++) {
    m[v[i]] = i;
  }

  for (int i = 0; i < v1.size(); i++) {
    cout << m[v1[i]] << " ";
  }

}