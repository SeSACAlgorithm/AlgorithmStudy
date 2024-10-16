#include <iostream>
#include <vector>

using namespace std;

#define DEFAULT_VAL 10000000

int main()
{
    int n;
    cin >> n;

    int temp;
    vector<vector<int>> roads(n, vector<int>(n, DEFAULT_VAL));
    // 0인 경우 디폴트 값(아주 큰 값)으로, 1인 경우 입력값으로 초기화
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> temp;
            if (temp > 0)
                roads[i][j] = temp;
        }
    }

    // 플로이드-워셜 알고리즘
    for (int mid = 0; mid < n; ++mid)
        for (int start = 0; start < n; ++start)
            for (int end = 0; end < n; ++end)
                roads[start][end] = min(roads[start][end], roads[start][mid] + roads[mid][end]);

    // 디폴트 값보다 작다면 경로가 존재하므로 1로,
    // 그대로 디폴트 값이라면 경로가 존재하지 않으므로 0으로 초기화
    vector<vector<int>> answer(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            answer[i][j] = roads[i][j] < DEFAULT_VAL ? 1 : 0;

    for(const vector<int>& ans : answer)
    {
        for (const int& num : ans)
            cout << num << " ";
        cout << "\n";
    }
}