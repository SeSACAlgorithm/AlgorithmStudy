#include <iostream> 

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); // 입출력 속도 향상
    cin.tie(0); // 입력 속도 최적화
    cout.tie(0); // 출력 속도 최적화

    int T; 
    cin >> T; 

    while (T--) { // T번 반복
        int N; 
        cin >> N; 

        int minNum = 1000001; // 큰 값으로 최소값 초기화
        int maxNum = -1000001; // 작은 값으로 최대값 초기화

        for (int i = 0; i < N; ++i) { // N번 반복
            int x;
            cin >> x; 

            if (x < minNum) minNum = x; // 최소값 갱신
            if (x > maxNum) maxNum = x; // 최대값 갱신
        }

        cout << minNum << " " << maxNum << "\n";
    }

    return 0; 
}
