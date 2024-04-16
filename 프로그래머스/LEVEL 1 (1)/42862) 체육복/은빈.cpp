#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n-lost.size();
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    //여벌 체육복이 있는 것 학생 중에 도난당한 학생이 있는지 체크
    for(int i=0; i<lost.size(); i++)
    {
        for(int j=0; j<reserve.size(); j++)
        {
            if(lost[i] == reserve[j])
            {
                answer++;
                lost[i] = -1;
                reserve[j] = -1;
                break;
            }
        }
    }

    // 도난당한 사람 앞, 뒤번호가 여벌 체육복이 있는지 체크
    for(int i=0; i<lost.size(); i++)
    {
        for(int j=0; j<reserve.size(); j++)
        {
            if(lost[i]-1 == reserve[j] || lost[i]+1 == reserve[j])
            {
                answer++;
                reserve[j] = -1;
                break;
            }
        }
    }
    return answer;
}