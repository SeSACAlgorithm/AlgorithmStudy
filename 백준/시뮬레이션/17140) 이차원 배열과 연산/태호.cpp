#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

int resultR, resultC, r = 3, c = 3, k, seconds = 0;
int board[101][101];


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> resultR >> resultC >> k;


    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> board[i][j];


    while (board[resultR - 1][resultC - 1] != k && seconds <= 100)
    {
        ++seconds;

        if (r >= c)
        {
            int newC = 0;

            for (int i = 0; i < r; ++i)
            {
                unordered_map<int, int> um;
                vector<pair<int, int>> vec;

                for (int j = 0; j < c; ++j)
                    if(board[i][j])
                        ++um[board[i][j]];
                    

                for(pair<int, int> cur : um)
                    vec.push_back({cur.first, cur.second});

                sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b) {

                    if (a.second == b.second)
                        return a.first < b.first;

                    return a.second < b.second;
                });


                int num = 0;

                for (pair<int, int> cur : vec)
                {
                    if(num >= 100) break;

                    board[i][num++] = cur.first;
                    board[i][num++] = cur.second;
                }

                for (int j = num; j < 100; ++j)
                    board[i][j] = 0;

                newC = max(newC, num);
            }

            c = newC;
        }
        else
        {
            int newR = 0;

            for (int i = 0; i < c; ++i)
            {
                unordered_map<int, int> um;
                vector<pair<int, int>> vec;

                for (int j = 0; j < r; ++j)
                    if (board[j][i])
                        ++um[board[j][i]];

                for (pair<int, int> cur : um)
                    vec.push_back({ cur.first, cur.second });

                sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b) {

                    if (a.second == b.second)
                        return a.first < b.first;

                    return a.second < b.second;
                    });


                int num = 0;

                for (pair<int, int> cur : vec)
                {
                    if (num >= 100) break;

                    board[num++][i] = cur.first;
                    board[num++][i] = cur.second;
                }


                for (int j = num; j < 100; ++j)
                    board[j][i] = 0;


                newR = max(newR, num);
            }

            r = newR;
            
        }
    }

    board[resultR - 1][resultC - 1] == k ? cout << seconds : cout << -1;

    return 0;
}
