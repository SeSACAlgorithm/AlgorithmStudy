#include <map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = 0;
    
    // int형 초과 방지
    vector<long long> nodes(a.begin(), a.end());
    // 노드별 연결 정보 저장
    map<int, vector<int>> connected;
    for (const vector<int>& vec : edges)
    {
        connected[vec[0]].emplace_back(vec[1]);
        connected[vec[1]].emplace_back(vec[0]);
    }
    
    // 임의의 노드를 루트로 설정
    int root = 0;
    
    // 몇 개의 자식 노드를 가지는지 저장
    // 루트는 전부 자식 노드로 연결되므로 connected의 사이즈를 그대로 저장
    // 이외에는 하나의 부모 노드를 가지므로 -1하여 저장
    vector<int> children_count(a.size());
    children_count[root] = connected[root].size();
    for(int i = root + 1; i < a.size(); ++i)
        children_count[i] = connected[i].size() - 1;

    // 루트부터 DFS로 순회한 후 리프 노드는 큐에 저장
    stack<int> stk;
    stk.push(root);
    vector<int> parent(a.size(), -1);
    queue<int> que;
    while (false == stk.empty())
    {
        int cur = stk.top();
        stk.pop();

        bool is_leaf = true;
        for (const int next : connected[cur])
        {
            if (next == parent[cur])
                continue;

            stk.push(next);
            parent[next] = cur;
            is_leaf = false;
        }

        if (is_leaf)
            que.push(cur);
    }

    // 리프 노드부터 올라가면서 부모 노드로 가중치 전달
    while(false == que.empty())
    {
        int cur = que.front();
        que.pop();
        if(cur == root) break;
        
        int p = parent[cur];
        nodes[p] += nodes[cur];
        answer += abs(nodes[cur]);
        // 연산 후 부모 노드의 자식 카운트 감소
        // 0이 되었다면 모든 자식 노드와 연산을 종료한 것이므로 큐에 추가
        --children_count[p];
        if(0 == children_count[p])
            que.push(parent[cur]);
    }
    // 루트가 0이 되었다면 조건을 만족했으므로 누적값 반환
    // 아니라면 -1 반환
    return nodes[root] == 0 ? answer : -1;
}