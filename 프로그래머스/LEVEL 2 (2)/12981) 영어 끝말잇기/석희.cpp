#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, bool> already_word;     // 단어, 나왔는지
map<int, int> person_count;                // 번호, 차례

bool right_answer(string last, string temp)
{
    // 1. 앞 사람이 말한 단어의 마지막 문자로 시작하는 단어인지
    if(last.back() != temp.front()) return false;

    // 2. 이전에 등장했던 단어인지
    if(already_word[temp] == true) return false;
    
    // 3. 한글자인 단어?
    if(temp.size() <= 1) return false;

    already_word[temp] = true;
    return true;
}

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    if(words[0].size() <= 1)  return vector<int>{1,1};

    int person_index = 0;
    for(int i = 0; i < words.size(); i++)
    {
        // 사람 인덱스 1부터 시작
        person_index++;
        person_count[person_index]++;
        
        // 첫단어는 반복문전에 체크했으므로 단어만 true 처리하고 넘기기
        if(i == 0)
        {
            already_word[words[i]] = true;
            continue;
        }
        
        // 규칙에 맞는지 확인 (안맞으면 바로 해당 번호와 차례 리턴)
        if(!right_answer(words[i-1], words[i])) return vector<int>{person_index, person_count[person_index]};
        
        // 한바퀴 돌았다면
        if(person_index % n == 0)  person_index = 0;
    }

    // 탈락자가 안생긴 경우
    return vector<int>{0,0};
}