#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 두 숫자를 조합했을 때 더 큰 값을 만드는 순서로 정렬하는 함수
bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> strs;

    // 숫자들을 문자열로 변환
    for (int num : numbers) {
        strs.push_back(to_string(num));
    }

    // 문자열들을 큰 수가 앞에 오도록 정렬
    sort(strs.begin(), strs.end(), compare);

    // 만약 가장 큰 숫자가 '0'이면 모든 숫자가 0인 경우이므로 "0" 반환
    if (strs[0] == "0") {
        return "0";
    }

    // 정렬된 문자열을 차례로 이어붙여 가장 큰 수 만들기
    string answer = "";
    for (string s : strs) {
        answer += s;
    }

    return answer;
}
