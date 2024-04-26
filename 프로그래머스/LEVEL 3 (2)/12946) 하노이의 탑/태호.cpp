#include <string>
#include <vector>

using namespace std;

void func(int a, int b, int n, vector<vector<int>>& answer)
{
    if (n == 1)
    {
        answer.push_back(vector<int>{a, b});
        return;
    }

    func(a, 6 - a - b, n - 1, answer);
    answer.push_back(vector<int>{a, b});
    func(6 - a - b, b, n - 1, answer);
}


vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    func(1, 3, n, answer);
    return answer;
}
