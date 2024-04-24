#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 != 0) //인덱스 몇부터 시작해? 0부터 그니까 홀수면 박이야
        {
            answer += "박";
        }
        else
        {
            answer += "수";
        }
    }

    return answer;
}