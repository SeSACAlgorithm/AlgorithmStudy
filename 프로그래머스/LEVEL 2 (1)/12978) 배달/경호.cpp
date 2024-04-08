#include <vector>
#include <queue>

using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;

    vector<vector<int>> roads(N + 1, vector<int>(N + 1, 500001));
    for(vector<int> vec : road)
    {
        if(roads[vec[0]][vec[1]] > vec[2])
        {
            roads[vec[0]][vec[1]] = vec[2];
            roads[vec[1]][vec[0]] = vec[2];
        }
    }

    vector<int> cities(N + 1, 500001);
    cities[1] = 0;
    queue<int> que;
    for(int i = 0; i < roads[1].size(); i++)
    {
        if(roads[1][i] < 500001)
        {
            que.push(i);
            cities[i] = roads[1][i];
        }
    }
    
    int cur = 0;
    while(false == que.empty())
    {
        cur = que.front();
        que.pop();
        
        for(int next = 0; next < roads[cur].size(); next++)
        {
            if(cities[cur] + roads[cur][next] < cities[next])
            {
                que.push(next);
                cities[next] = cities[cur] + roads[cur][next];
            }
        }
    }
    
    for(int i = 1; i < cities.size(); i++)
        if(cities[i] <= K)
            answer++;
    return answer;
}