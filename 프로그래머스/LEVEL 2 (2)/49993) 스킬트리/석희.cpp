// 문제 분석
/*
    - 선행 스킬 순서 skill / 유저들이 만든 스킬트리 배열 skill_trees
    - 가능한 스킬 트리 개수 return

    check_skill_tree 함수
    1. 유저들의 스킬 트리를 검사하면서 선행 스킬 트리 순서에 그 스킬이 있는지 확인
    2. 만약 그 스킬이 선행 스킬 트리에 있는데, 순서대로 나오지 않았다면 ("CBD" / "CD") 불가능한 스킬트리 -> return false
    3. 중간에 끊기지 않고 다 검사가 됐다면 가능한 스킬 트리이므로 return true

    solution 함수
    - check_skill_tree를 벡터안의 문자열마다 반복하면서 true가 나온 값만 answer 증가
*/

#include <string>
#include <vector>

using namespace std;

bool check_skill_tree(string skill, string skill_tree)
{
    int index = 0;
    for (char c_skill_tree : skill_tree)
    {
        if (skill.find(c_skill_tree) == string::npos) continue;                 // 문자열이 존재하지 않는다면
        
        if(index < skill.size() && skill[index] == c_skill_tree) index++;       // 순서대로 스킬이 나왔다면
        else return false;
    }

    return true;
}

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;

    for(int i = 0; i < skill_trees.size(); i++)
    {
        if(check_skill_tree(skill, skill_trees[i])) answer++;
    }

    return answer;
}