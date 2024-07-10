#include <string>
#include <iostream>
using namespace std;

string solution(string new_id) {
    string answer = "";

    // 대문자를 소문자로 
    for (size_t i = 0; i < new_id.size(); i++) 
        new_id[i] = tolower(new_id[i]);

    // 빼기(-), 밑줄(_), 마침표(.)만 남기기
    for (size_t i = 0; i < new_id.size(); i++) {
        if ((new_id[i] >= 'a' && new_id[i] <= 'z') || 
            (new_id[i] >= '0' && new_id[i] <= '9') || 
            new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') {
            answer += new_id[i];
        }
    }

    // 연속된 마침표(.) 처리
   new_id.clear(); // 마침표 처리된 새로운 문자열 추가 위해 clear!!!
    for (int i = 0; i < answer.size(); i++) {
        // 현재 문자가 마침표(.)이고 다음 문자가 있고 마침표(.)인 경우 현재 문자를 건너뜀 
        if (answer[i] == '.' && i + 1 < answer.size() && answer[i + 1] == '.') {
            continue;
        }
        new_id += answer[i];
    }


    // 처음이나 끝 마침표(.) 제거
    if (!new_id.empty() && new_id.back() == '.') 
        new_id.pop_back();
    if (!new_id.empty() && new_id.front() == '.') 
        new_id.erase(0, 1);

    // 빈 문자열 처리
    if (new_id.empty()) 
        new_id += 'a';

    // 길이 제한
    if (new_id.size() >= 16) {
        while (new_id.size() > 15) {
            new_id.pop_back();
        }
    }
   // 길이 수정 후 끝이 마침표(.)일 경우 제거
    if (new_id.back() == '.') 
        new_id.pop_back();

    // 길이 2이하면 마지막 문자 추가
    while (new_id.size() <= 2) {
        new_id += new_id.back();
    }

    return new_id;
}
