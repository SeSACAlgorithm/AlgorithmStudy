#include<iostream>
using namespace std;

int main() {
    int N, K;
    int ans = 0; 

    cin >> N >> K;

    // 시간, 분, 초에 대해 각각 반복문을 돌면서 k가 포함된 경우를 찾는다
    for (int h = 0; h <= N; h++) {
        for (int m = 0; m < 60; m++) {
            for (int s = 0; s < 60; s++) {
                // 시간의 각 자리에서 k가 있는지 확인
                if (h / 10 == K || h % 10 == K ||
                    m / 10 == K || m % 10 == K ||
                    s / 10 == K || s % 10 == K) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
