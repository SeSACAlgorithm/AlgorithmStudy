#include <iostream>
#include <vector>

using namespace std;

int n, m;

int board[502][502];
int result = 0;

vector<vector<pair<int, int>>> Tet[5] = 
{

    // 첫 번째 블록 (I 모양)
    {
        {{0,0}, {0,1}, {0,2}, {0,3}},
        {{0,0}, {1,0}, {2,0}, {3,0}},
    },

    // 첫 번째 블록 (ㅁ 모양)
    {
        { {0,0}, {0,1}, {1,0}, {1,1} },
    },

    // 세 번째 블록 (L 모양)
    {
        { {0,0}, {1,0}, {2,0}, {2,1} },
        { {0,1}, {1,1}, {2,1}, {2,0} },

        { {1,0}, {0,0}, {0,1}, {0,2} },
        { {0,0}, {1,0}, {1,1}, {1,2} },

        { {0,0}, {0, 1}, {1, 1}, {2, 1} },
        { {2,0}, {1,0}, {0,0}, {0, 1} },

        { {1,0}, {1, 1}, {1, 2}, {0, 2} },
        { {0,0}, {0,1}, {0,2}, {1, 2} }
    },

    
    // 네 번째 블록 (ㄹ 모양)
    {
        { {0,0}, {1,0}, {1,1}, {2,1} },
        { {0,1}, {1,1}, {1,0}, {2,0} },
        { {1,0}, {1,1}, {0,1}, {0,2} },
        { {0,0}, {0,1}, {1,1}, {1,2} }
    },

    // 네 번째 블록 (ㅏ 모양)
    {
        { {0,0}, {1,0}, {1,1}, {2,0} },
        { {0,1}, {1,1}, {1,0}, {2,1} },

        { {0,0}, {0,1}, {0, 2}, {1, 1} },
        { {1,0}, {1,1}, {1,2}, {0, 1} }
    }

};

void Solve(int r, int c)
{
    for (int k = 0; k < 5; ++k)
    {
        for (int i = 0; i < Tet[k].size(); ++i)
        {
            int cnt = 0;

            for (int j = 0; j < Tet[k][i].size(); ++j)
            {
                int nx = r + Tet[k][i][j].first;
                int ny = c + Tet[k][i][j].second;

                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                {
                    cnt = -1;
                    break;
                }

                cnt += board[nx][ny];
            }

            result = max(result, cnt);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> board[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            Solve(i, j);

    cout << result;
}
