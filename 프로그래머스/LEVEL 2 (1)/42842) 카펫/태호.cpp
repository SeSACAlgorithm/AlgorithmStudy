#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int sum = brown + yellow;
    int i = 3;

    while (true)
    {
        int divide = sum / i;
        if (!(sum % i))
        {
            if(yellow == (divide - 2) * (i - 2))
            {
                answer.push_back(divide);
                answer.push_back(i);
                break;
            }
        }

        ++i;
    }

    return answer;
}
