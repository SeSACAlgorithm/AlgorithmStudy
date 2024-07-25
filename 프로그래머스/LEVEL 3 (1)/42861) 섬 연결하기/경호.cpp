#include <queue>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct road
{
    int island_a;
    int island_b;
    int cost;
    
    road() : island_a(0), island_b(0), cost(0) {}
    road(int a, int b, int c) : island_a(a), island_b(b), cost(c) {}
};

// 재귀적으로 최상위 부모를 찾아 반환
int get_parent(const vector<int>& parent, int idx)
{
    return parent[idx] == idx ? idx : get_parent(parent, parent[idx]);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    // 비용 순으로 정렬
    vector<road> roads(costs.size());
    for(int i = 0; i < costs.size(); ++i)
        roads[i] = road(costs[i][0], costs[i][1], costs[i][2]);
    sort(roads.begin(), roads.end(), [](road a, road b) { return a.cost < b.cost; });
    
    // 연결된 노드 중 낮은 번호쪽을 부모로 저장
    vector<int> parent(n);
    for(int i = 0; i < n; ++i)
        parent[i] = i;
    
    for(int i = 0; i < roads.size(); ++i)
    {
        int a = roads[i].island_a;
        int b = roads[i].island_b;
        int pa = parent[a];
        int pb = parent[b];
        
        // 부모가 같다면 이미 같은 그룹으로 연결되어 있으므로 스킵
        if(parent[a] == parent[b]) continue;
        
        answer += roads[i].cost;
        // 낮은 번호쪽을 부모로 설정
        // 기존에 저장된 부모 노드를 새로운 부모 노드로 갱신 
        if(parent[a] > parent[b])
        {
            parent[a] = get_parent(parent, b);
            auto it = parent.begin();
            while((it = find(it, parent.end(), pa)) != parent.end())
                *it = parent[a];
        }
        else
        {
            parent[b] = get_parent(parent, a);
            auto it = parent.begin();
            while((it = find(it, parent.end(), pb)) != parent.end())
                *it = parent[b];
        }
        
        // 모든 노드가 연결되었다면 parent의 모든 원소가 0
        // 최대값이 0이라면 모든 노드가 연결된 것이므로 break
        if(*max_element(parent.begin(), parent.end()) == 0)
            break;
    }
    
    return answer;
}