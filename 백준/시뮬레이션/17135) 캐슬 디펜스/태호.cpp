#include<bits/stdc++.h>

using namespace std;


// 적의 개수 칸마다 최대 1개
// 격자판의 N번행 바로 아래의 모든 칸에는 성이 있다.
int n, m, d, result = 0;
int board[20][20];
int sub[20][20];

int dx[3] = { 0, -1, 0 };
int dy[3] = { -1, 0, 1 };

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> d;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> board[i][j];

    vector<int> vec(m, 0);

    for(int i = 0; i < 3; ++i)
        vec[i] = 1;


    do
    {
        int cnt = 0;

        vector<pair<int, int>> tmp;
        vector<pair<int, int>> enemyPos;
        
        memcpy(sub, board, sizeof(int) * 20 * 20);

        for (int i = 0; i < vec.size(); ++i)
            if(vec[i])  
                tmp.push_back({n, i});


        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if(sub[i][j])
                    enemyPos.push_back({i, j});
            }
        }

        for (int k = 0; k < n; ++k)
        {
            vector<pair<int, int>> dead;

            for (int i = 0; i < tmp.size(); ++i)
            {
                vector<tuple<int, int, int>> test;

                for (int j = 0; j < enemyPos.size(); ++j)
                {
                    int x = enemyPos[j].first;
                    int y = enemyPos[j].second;

                    //|r1-r2| + |c1-c2|
                    int dist = abs(x - tmp[i].first) + abs(y - tmp[i].second);
                    
                    if(dist <= d)
                        test.push_back({ dist, y, x });
                }

                if (!test.empty())
                {
                    sort(test.begin(), test.end());
                    auto [dist, y, x] = test[0];
                    dead.push_back({ x, y });
                }
             
            }

            for (int i = 0; i < dead.size(); ++i)
            {
                int x = dead[i].first, y = dead[i].second;
                
                if (sub[x][y])
                {
                    sub[x][y] = 0;
                    ++cnt;
                }
                
            }

            enemyPos.clear();

            for (int i = n - 1; i >= 0; --i)
            {
                for (int j = m - 1; j >= 0; --j)
                {
                    if (sub[i][j])
                    {
                        if (i + 1 != n)
                        {
                            ++sub[i + 1][j];
                            enemyPos.push_back({ i + 1, j });
                        }
                            

                        --sub[i][j];
                    }
                        
                }
            }

            if(enemyPos.empty())
                break;

        }


        result = max(result, cnt);
        

    } while(prev_permutation(vec.begin(), vec.end()));
 

    cout << result;

    return 0;
}
