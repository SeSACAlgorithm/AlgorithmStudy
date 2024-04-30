#include <vector>
#include <map>

using namespace std;

int solution(int N, int number) {
    if(number == N) return 1;
    
    vector<vector<int>> DP(8, vector<int>());
    DP[0].push_back(N);
    
    int tmp = 0;
    for (int i = 1; i < 8; ++i)
    {
        map<int, bool> check;
        int small = 0, big = i - 1;
        while(small <= big)
        {
            for(int j = 0; j < DP[small].size(); ++j)
            {
                for(int k = 0; k < DP[big].size(); ++k)
                {
                    tmp = DP[small][j] + DP[big][k];
                    if (false == check[tmp])
                    {
                        DP[i].push_back(tmp);
                        check[tmp] = true;
                    }

                    tmp = DP[small][j] - DP[big][k];
                    if (false == check[tmp])
                    {
                        DP[i].push_back(tmp);
                        check[tmp] = true;
                    }

                    tmp = DP[big][k] - DP[small][j];
                    if (false == check[tmp])
                    {
                        DP[i].push_back(tmp);
                        check[tmp] = true;
                    }

                    tmp = DP[small][j] * DP[big][k];
                    if (false == check[tmp])
                    {
                        DP[i].push_back(tmp);
                        check[tmp] = true;
                    }

                    if(DP[big][k] != 0)
                    {
                        tmp = DP[small][j] / DP[big][k];
                        if (false == check[tmp])
                        {
                            DP[i].push_back(tmp);
                            check[tmp] = true;
                        }
                    }

                    if (DP[small][j] != 0)
                    {
                        tmp = DP[big][k] / DP[small][j];
                        if (false == check[tmp])
                        {
                            DP[i].push_back(tmp);
                            check[tmp] = true;
                        }
                    }
                }
            }
            
            ++small;
            --big;
        }
        
        // NNN 
        tmp = N;
        for (int j = 0; j < i; ++j)
        {
            tmp = tmp * 10 + N;
        }
        DP[i].push_back(tmp);
        check[tmp] = true;

        if (check[number])
            return i + 1;
    }
    
    return -1;
}