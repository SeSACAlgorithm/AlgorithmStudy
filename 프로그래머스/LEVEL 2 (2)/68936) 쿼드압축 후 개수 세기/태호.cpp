#include <string>
#include <vector>

using namespace std;

pair<int, int> nums;
int ans[1030][1030];


bool cmp(int x, int y, int n)
{
    for (int i = x; i < x + n; ++i)
        for (int j = y; j < y + n; ++j)
            if (ans[x][y] != ans[i][j])
                return false;

    return true;
}

void QuadTree(int x, int y, int n)
{
    if (!cmp(x, y, n))
    {
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                QuadTree(x + i * n / 2, y + j * n / 2, n / 2);
    }
    else
        ans[x][y] ? ++nums.second : ++nums.first;
}


vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;

    for(int i = 0; i < arr.size(); ++i)
        for(int j = 0; j < arr[i].size(); ++j)
            ans[i][j] = arr[i][j];

    QuadTree(0, 0, arr.size());

    answer.push_back(nums.first);
    answer.push_back(nums.second);

    return answer;
}
