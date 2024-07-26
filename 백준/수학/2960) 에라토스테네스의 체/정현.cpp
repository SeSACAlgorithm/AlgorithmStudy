#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    bool arr[1001] = {false};  // 소수 여부를 저장
    int count = 0, result = 0; 

    for (int i = 2; i <= N; i++) {
        if (arr[i]) continue; // 이미 제거된 수는 건너뛴다

        for (int j = i; j <= N; j += i) { // i의 배수를 제거
            if (!arr[j]) { // j가 아직 제거되지 않은 경우
                arr[j] = true; // j를 제거
                count++; // 제거된 수의 개수 증가

                if (count == K) { // K번째 제거된 수를 찾으면 종료
                    result = j;
                    break;
                }
            }
        }
        if (count == K) break; 
    }

    cout << result << '\n'; 
    return 0;
}
