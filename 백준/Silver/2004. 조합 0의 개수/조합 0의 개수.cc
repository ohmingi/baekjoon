#include <iostream>
using namespace std;

long long count_p(long long n, int p) {
    long long cnt = 0;
    while (n > 0) {
        cnt += n / p;
        n /= p;
    }
    return cnt;
}

int main() {
    long long n, m;
    cin >> n >> m;

    long long two = count_p(n, 2) - count_p(m, 2) - count_p(n-m, 2);
    long long five = count_p(n, 5) - count_p(m, 5) - count_p(n-m, 5);

    int a = min(two, five);

    cout << a;
}


