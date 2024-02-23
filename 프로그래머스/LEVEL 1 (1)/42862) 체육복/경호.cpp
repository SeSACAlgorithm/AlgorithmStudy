#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    sort(lost.begin(), lost.end());
    
    map<int, bool> m;
    for(int i = 0; i < reserve.size(); i++)
        m[reserve[i]] = true;
    
    // 자기가 가지고 있는 경우
    for(int i = 0; i < lost.size(); i++)
    {
        if(m[lost[i]])
        {
            m[lost[i]] = false;
            lost[i] = -1;
        }
    }
    
    // 남에게 빌리는 경우
    for(int i = 0; i < lost.size(); i++)
    {
        // 도난당했으나 자기가 가지고 있던 경우
        if(lost[i] == -1)
            continue;
        
        if(m[lost[i] - 1])
            m[lost[i] - 1] = false;
        else if(m[lost[i] + 1])
            m[lost[i] + 1] = false;
        else // 끝내 못빌린 경우
            answer--;
    }
    return answer;
}