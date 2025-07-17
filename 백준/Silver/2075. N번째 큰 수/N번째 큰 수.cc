#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int numArray[N * N];

    for (int i = 0; i < N * N; i++) {
        cin >> numArray[i];
    }

    sort(numArray,numArray+N*N);
    cout << numArray[N * N - N] << "\n";

    return 0;
}