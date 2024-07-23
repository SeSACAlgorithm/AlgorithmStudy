#include<iostream>
using namespace std;

// 최대 공약수 구하는 함수
int gcd(int x, int y) {
    while(y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

int main() {
    int n, a, b, c;

    cin >> n;

    if(n == 2)
        cin >> a >> b;
    else
        cin >> a >> b >> c;

    int result = (n == 2) ? gcd(a, b) : gcd(gcd(a, b), c);

    for(int i = 1; i <= result; i++) {
        if(result % i == 0)
            cout << i << endl;
    }

    return 0;
}
