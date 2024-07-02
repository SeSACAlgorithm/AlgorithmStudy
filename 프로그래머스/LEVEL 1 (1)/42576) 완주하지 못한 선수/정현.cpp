#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    // 참여자와 완주자 배열을 정렬 비교하자
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    int i = 0;
    
    // 하나씩 비교하다가ㅏ 값이 다르면 완주하지 못한선수야.
    for (; i < completion.size(); i++)
        if (participant[i] != completion[i])
            break;
    
    // 순서대로 다 같으면 마지막 참여자가 완주하지 못한 선수
    return participant[i];
}
