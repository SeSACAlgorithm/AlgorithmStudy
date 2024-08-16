#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    // 1. 문자열의 각 문자를 벡터에 추가
    vector<char> characters(s.begin(), s.end());
    
    // 2. 벡터를 정렬
    sort(characters.begin(), characters.end(), greater<char>());
    
    // 3. 정렬된 벡터를 다시 문자열로 변환
    answer = string(characters.begin(), characters.end());
    
    return answer;
}
