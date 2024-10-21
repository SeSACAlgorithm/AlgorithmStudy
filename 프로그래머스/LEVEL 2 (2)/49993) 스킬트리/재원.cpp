#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for (const string& tree : skill_trees) {
        int skillIndex = 0; // 현재 skill의 인덱스
        bool isValid = true; // 현재 스킬 트리가 유효한지 확인하는 변수

        for (char c : tree) {
            auto t = find(skill.begin(), skill.end(), c); // 현재 스킬이 vSkill에 있는지 검색
            
            if (t != skill.end()) { // 현재 스킬이 skill에 있을 경우
                if (skillIndex < skill.size() && c == skill[skillIndex]) {
                    // 현재 스킬이 스킬의 다음 스킬과 일치하면 인덱스를 증가
                    skillIndex++;
                } else {
                    // 현재 스킬이 이전 스킬이 아니라면 유효하지 않음
                    isValid = false;
                    break;
                }
            }
        }

        if (isValid) {
            answer++; // 유효한 스킬 트리 카운트 증가
        }
    }

    return answer;
}
