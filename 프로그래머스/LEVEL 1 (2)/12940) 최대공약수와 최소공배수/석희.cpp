#include <string>
#include <vector>

using namespace std;

int findMaxDiv(int n, int m)
{
    if (m % n == 0)
        return n;
    for (int i = n; i >= 1; i--)
    {
        if (m % i == 0 && n % i == 0)
            return i;
    }
}

vector<int> solution(int n, int m)
{
    vector<int> answer;
    int maxDiv = findMaxDiv(min(n, m), max(n, m));
    answer.push_back(maxDiv);
    answer.push_back(n * m / maxDiv);
    return answer;
}
