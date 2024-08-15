#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int len = number.length() - k;
    int next_index = 0;
    int index = 0;

    while(answer.length() < len)
    {
        answer += " ";

        for(int i = next_index; i <= k; i++)
        {
            if(answer[index] < number[i])
            {
                answer[index] = number[i];
                next_index = i + 1;
            }
        }
        k++;
        index++;
    }

    
    return answer;
}