#include <iostream>
using namespace std;

int ant = 0;
int n;

void count(int r, int c, int size) {
    if (size == 2) {
        if (r % 2 == 0 && c % 2 == 0) {}
        else if (r % 2 == 0 && c % 2 == 1) ant += 1;
        else if (r % 2 == 1 && c % 2 == 0) ant += 2;
        else ant += 3;
        return;
    }
    int half_size = size / 2;
    if (r < half_size && c < half_size) count(r, c, half_size);
    else if (r < half_size && c >= half_size) {
        ant += half_size * half_size;
        count(r, c - half_size, half_size);
    }
    else if (r >= half_size && c < half_size) {
        ant += 2 * half_size * half_size;
        count(r - half_size, c, half_size);
    }
    else {
        ant += 3 * half_size * half_size;
        count(r - half_size, c - half_size, half_size);
    }
}

int main() {
    int r, c;

    cin >> n >> r >> c;
    int size = 1 << n; // 2^n을 계산

    count(r, c, size);

    cout << ant<< "\n";
}
