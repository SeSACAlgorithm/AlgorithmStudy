#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> arr;

    // 숫자를 일의 자리부터 차례대로 배열에 추가
    while (n > 0) {
        arr.push_back(n % 10);
        n /= 10;
    }
    // 열을 내림차순으로 정렬
    sort(arr.begin(), arr.end(), greater<int>());
    // 정렬된 배열의 요소를 answer에 일의 자리부터 차례대로 추가
    for (int i = 0; i < arr.size(); i++) {
        answer *= 10; // 이거 안해주면 모든 숫자 더하게 된다. 아래에 있으면 처음 수에 10이 곱해져서 원하는 출력값 *10됨
        answer += arr[i];
    }

    return answer;

}