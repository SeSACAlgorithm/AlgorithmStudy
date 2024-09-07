#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, k;

int dist[200002];
bool visit[200002];

const int MX = 500000;

queue<int> que;

void Teleport(int cur)
{
    for (int i = cur * 2; i < 100001; i *= 2)
    {
        if (visit[i] && dist[i] <= dist[cur]) break;
        visit[i] = true;
        dist[i] = dist[cur];
        que.push(i);
    }
}

void Walk(int cur)
{
    for (int num : {cur - 1, cur + 1})
    {
        if (num < 0 || num > 100000) continue;
        if (dist[num] <= dist[cur] + 1 || visit[num]) continue;

        dist[num] = dist[cur] + 1;
        visit[num] = true;
        que.push(num);
    }
}

int main(void) {

    ios::sync_with_stdio(0); cin.tie(0);
        
    cin >> n >> k;

    fill(dist, dist + 200002, MX);
    
    que.push(n);
    dist[n] = 0;

    while (dist[k] == MX)
    {
        int cur = que.front();
        que.pop();

        Teleport(cur);
        Walk(cur);
    }

    cout << dist[k];
    
}
