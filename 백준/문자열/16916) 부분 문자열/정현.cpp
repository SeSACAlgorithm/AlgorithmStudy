#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * KMP(Knuth-Morris-Pratt) 알고리즘:
 * 문자열 검색 알고리즘으로, 주어진 텍스트에서 특정 패턴을 빠르게 찾는다.
 * 핵심은 "실패 함수"를 사용해, 패턴이 일치하지 않을 때 불필요한 비교를 피하고
 * 패턴 내에서 일치했던 부분을 재활용하여 탐색 속도를 높이는 것이다.
 * 시간 복잡도는 O(n + m)으로, n은 텍스트의 길이, m은 패턴의 길이다.
 */

// 실패 함수 생성
// 패턴 문자열에서 접두사와 접미사가 일치하는 최대 길이 구하기
vector<int> createFailureFunction(const string& pattern) {
    int m = pattern.length();
    vector<int> failure(m, 0);  // 실패 함수 테이블
    int j = 0;  // 접두사, 접미사가 일치하는 최대 길이 저장하는 변수

    // 패턴 문자열을 순회하면서 실패 함수 테이블 채우기
    for (int i = 1; i < m; i++) {
        // 패턴이 일치하지 않는 경우 이전 접두사의 길이로 이동
        while (j > 0 && pattern[i] != pattern[j]) {
            j = failure[j - 1];  // 일치하지 않으면 j값을 이전 일치 위치로 변경
        }
        // 패턴이 일치하는 경우 실패 함수 테이블에 값을 채우기
        if (pattern[i] == pattern[j]) {
            failure[i] = ++j;  // 일치할 때는 접두사,접미사 길이 증가
        }
    }
    return failure;
}

// 주어진 텍스트에서 패턴 찾기
// 패턴이 텍스트에 포함되면 true, 그렇지 않으면 false
bool KMP(const string& text, const string& pattern) {
    int textLength = text.length(); 
    int patternLength = pattern.length(); 
    if (patternLength == 0) return true;   // 패턴이 비어있다면 항상 매칭된 것으로 간주

    vector<int> failure = createFailureFunction(pattern);  // 실패 함수 테이블 생성
    int j = 0;  // 패턴을 순회하는 포인터

    // 텍스트를 순회하면서 패턴을 찾는다.
    for (int i = 0; i < textLength; i++) {
        // 패턴이 일치하지 않는 경우, 실패 함수 테이블을 이용해 j값 조정
        while (j > 0 && text[i] != pattern[j]) {
            j = failure[j - 1];  // 일치하지 않을 때 j를 패턴의 이전 위치로 이동
        }
        // 패턴이 일치하는 경우
        if (text[i] == pattern[j]) {
            j++;  // 패턴이 일치하면 j를 증가시켜 다음 문자 비교
        }
        // 패턴의 끝까지 일치한 경우
        if (j == patternLength) {
            return true;  // 패턴이 텍스트에 포함된 경우
        }
    }
    return false;  // 패턴이 텍스트에 포함되지 않은 경우
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);

    string S, P;
    cin >> S >> P;  

    // 패턴이 텍스트에 포함되어 있으면 1, 그렇지 않으면 0 출력
    cout << (KMP(S, P) ? 1 : 0) << '\n';

    return 0;
}
