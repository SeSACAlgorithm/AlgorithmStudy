#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    
    vector<int> students(n + 2, 0);
    
    // 1. reserve / lost 정보 반영
    for (int i = 0; i < lost.size(); i++)
    {
        students[lost[i]] = -1;
    }
    for (int i = 0; i < reserve.size(); i++)
    {
        students[reserve[i]] += 1;
    }

    // 2. 여분을 기준으로 하여 체육복을 빌려준다.

    for (int i = 1; i < students.size(); i++)
    {
        if (students[i] < 1)
            continue;

        else if (students[i - 1] == -1)
        {
            students[i] -= 1;
            students[i - 1] += 1;
        }

        else if (students[i + 1] == -1)
        {
            students[i] -= 1;
            students[i + 1] += 1;
        }
    }
    // 3. 체육복을 갖고 있는 학생 수 를 계산한다.
    for(int i = 1; i < students.size(); i++)
    {
        if(students[i] < 0)
            n -= 1;
    }
    return n;
}
