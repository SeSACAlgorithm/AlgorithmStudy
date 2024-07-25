#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            cout << i << endl; 
            n /= i;
        }
    }
    // 만약 n이 소수이고 1보다 크면 마지막으로 출력
    if (n > 1) {
        cout << n << endl;
    }

    return 0;
}
