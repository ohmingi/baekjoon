#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int a, p;
vector<int> v;


int sum(int n) {
	string str = to_string(n);
	int s = 0;
	int b = 1;

	for (int i = 0; i < str.size(); i++) {
		b = 1;
		for (int t = 0; t < p; t++) {
			b *= (str[i] - '0');
			//cout << b << " ";
		}
		s += b;
	}
	//cout << s << "\n";
	return s;
}

void bfs() {
	queue<int> q;
	q.push(a);
	v.push_back(a);

	while (!q.empty()) {
		int cnt = q.front();
		q.pop();

		cnt = sum(cnt);
		//out << cnt << "\n";
		auto it = find(v.begin(), v.end(), cnt);
		if (it == v.end()) {
			v.push_back(cnt);
			//cout << *(v.end()-1) << " ";
		}
		else{
			cout << it - v.begin();
			break;
		}

		q.push(cnt);
	}
}

int main() {
	cin >> a >> p;
	bfs();
}