#include <string>
#include <vector>

using namespace std;

int nums[1001];
int ans[1001][1001];

int N;

void dfs(int dist, int xStart, int yStart, int endX, int endY, int idx)
{
    if(nums[N] == idx)
        return;

    if (dist % 3 == 0)
    {
        for (int i = yStart; i <= endY; ++i)
        {
            ans[i][xStart] = ++idx;

            if (nums[N] == idx)
                return;
        }


        dfs(dist + 1, xStart + 1, yStart + 1, endX, endY, idx);
    }

    if (dist % 3 == 1)
    {
        for (int i = xStart; i <= endX; ++i)
        {
            ans[endY][i] = ++idx;

            if (nums[N] == idx)
                return;
        }


        dfs(dist + 1, xStart, yStart, endX - 1, endY - 1, idx);
    }

    if (dist % 3 == 2)
    {
        for (int i = endY, j = endX; i >= yStart; --i, --j)
        {
            ans[i][j] = ++idx;

            if (nums[N] == idx)
                return;
        }

        dfs(dist + 1, xStart, yStart + 1, endX - 1, endY, idx);
    }


}

vector<int> solution(int n) {
    vector<int> answer;
    // % 4
    N = n;

    nums[0] = 0;
    nums[1] = 1;

    for(int i = 2; i <= n; ++i)
        nums[i] = i + nums[i - 1];

    dfs(0, 0, 0, n - 1, n -1, 0);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j)
            answer.push_back(ans[i][j]);

    return answer;
}
