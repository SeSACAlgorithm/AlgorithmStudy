#include <string>
#include <vector>
#include <algorithm>
using namespace std;


//1.각각의 배열을 정렬한다 
//2.정렬된 두 배열을 반복문으로 비교하여 다른게 있으면 추출 

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    
    string temp=participant[0];
    
        for (int i = 0; i < completion.size(); ++i) {
        if (participant[i] != completion[i]) {
            // 첫 번째로 일치하지 않는 이름이 완주하지 못한 선수
            return participant[i];
        }
    }
    
    // 모든 완주자가 일치하면, 마지막 남은 선수가 완주하지 못한 선수
    return participant.back();
    
    return answer;
}
