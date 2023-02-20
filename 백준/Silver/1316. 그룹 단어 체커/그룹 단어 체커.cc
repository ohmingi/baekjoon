#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int s;
	cin >> s;

	int count=0;
	string word;

	for (int i{ 0 }; i < s; i++) {
		cin >> word;
		int size = word.size();
		bool flag = true;

		for (int i = 0; i < size; i++) {
			for (int k = 0; k < i; k++) {
				if (word[i] != word[i - 1] && word[i] == word[k]) {
					flag = false;
					break;
				}
			}
		}
		if (flag) {
			count++;
		}
	}

	cout << count;

}