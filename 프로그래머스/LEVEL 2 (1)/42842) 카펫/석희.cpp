#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;
    int area = brown + yellow;
    int w = 0;

    for (int h = 3; h <= area; h++)
    {
        if (area % h == 0)
        {
            w = area / h;
            if ((w - 2) * (h - 2) == yellow)
            {
                answer.push_back(w);
                answer.push_back(h);
                break;
            }
        }
    }

    return answer;
}