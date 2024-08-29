#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// 원본 2차원 벡터에서 r, c만큼 떨어진 위치부터 len만큼 복사하는 함수
// 복사 후 스택에 추가
void add_quarter(const vector<vector<int>>& origin, stack<vector<vector<int>>>& stk, int r, int c, int len)
{
    vector<vector<int>> quarter(len, vector<int>(len));
    for(int i = 0; i < len; ++i)
        copy_n(origin[i + r].begin() + c, len, quarter[i].begin());

    stk.push(quarter);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<vector<int>> paper(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> paper[i][j];

    int white = 0, blue = 0;
    stack<vector<vector<int>>> stk; // 분할 벡터를 저장
    stack<pair<int, int>> point; // 시작 지점 좌표를 저장
    stk.push(paper);
    point.emplace(0, 0);
    while(false == stk.empty())
    {
        vector<vector<int>> cur = stk.top();
        stk.pop();
        int len = cur.size();

        int y = point.top().first;
        int x = point.top().second;
        point.pop();

        if(len == 1) // 길이가 1이라면 정답 카운팅
        {
            if (cur[0][0] == 0) ++white;
            else                ++blue;
            continue;
        }

        // 분할된 2차원 벡터를 돌며 [0][0]값과 같은지 검사
        // 한번이라도 다른 값이 나오면 즉시 종료
        int target = cur[0][0];
        bool one_color = true;
        for (int i = 0; i < len; ++i)
        {
            for (int j = 0; j < len; ++j)
            {
	            if(cur[i][j] != target)
	            {
                    one_color = false;
                    break;
	            }
            }
            if (false == one_color)
                break;
        }

        // 전부 동일한 컬러라면 정답 카운팅
        // 다른 값이 존재한다면 4분할하여 스택에 저장(좌표도 함께)
        if(one_color)
        {
            if (target == 0) ++white;
            else             ++blue;
        }
        else
        {
            const int half = len / 2;
            add_quarter(paper, stk, y, x, half);               point.emplace(y, x);
            add_quarter(paper, stk, y, x + half, half);        point.emplace(y, x + half);
            add_quarter(paper, stk, y + half, x, half);        point.emplace(y + half, x);
            add_quarter(paper, stk, y + half, x + half, half); point.emplace(y + half, x + half);
        }
    }

    cout << white << "\n" << blue;
}