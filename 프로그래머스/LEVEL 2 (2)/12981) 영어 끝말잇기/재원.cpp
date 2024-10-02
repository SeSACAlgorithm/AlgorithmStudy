#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    unordered_set<string> usedWords; // 사용된 단어를 저장
    vector<int> answer;

    // 첫 번째 단어는 아무것도 없으므로 초기화
    char lastChar = words[0][0];

    for (int i = 0; i < words.size(); i++) {
        // 이전 단어의 마지막 문자와 현재 단어의 첫 문자가 일치하지 않거나,
        // 이미 사용된 단어일 경우
        if ((i > 0 && words[i][0] != lastChar) || usedWords.count(words[i]) > 0) {
            answer.push_back((i + 1) % n == 0 ? n : (i + 1) % n); // 플레이어 번호
            answer.push_back((i + 1) / n + (i + 1) % n == 0 ? 1 : 0); // 차례
            return answer;
        }
        
        // 단어 사용 등록
        usedWords.insert(words[i]);
        // 마지막 문자 업데이트
        lastChar = words[i].back();
    }

    // 모든 규칙을 지킨 경우
    return {0, 0};
}
