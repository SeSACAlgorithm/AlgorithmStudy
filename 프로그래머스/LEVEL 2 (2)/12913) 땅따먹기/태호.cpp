#include <iostream>
#include <vector>
using namespace std;

int dist[100001][4];

void Checkdist(int index, const vector<int>& land)
{
    for (int i = 0; i < land.size(); ++i)
    {
        for (int j = 0; j < land.size(); ++j)
        {
            if(i == j) continue;
            
            dist[index][i] = max(dist[index][i], dist[index - 1][j] + land[i]);
        }
    }
}

int solution(vector<vector<int>> land)
{
    int answer = 0;
    for(int i = 0; i < 4; ++i)
        dist[0][i] = land[0][i];

    for (int i = 1; i < land.size(); ++i)
    {
        Checkdist(i, land[i]);
    }

    for(int i = 0; i < 4; ++i)
        answer = max(dist[land.size() - 1][i], answer);
    

    return answer;
}
