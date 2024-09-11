#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int N; 
    cin >> N; 

    long long result = 1; 

    // 팩토리얼 계산
    for (int i = 2; i <= N; i++) {
        result *= i; // 1부터 n까지 숫자를 곱함
    }

    cout << result << '\n'; 

    return 0; 
}
