#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    int leafs = 0, root = 0;
    vector<vector<int>> children(N);
    vector<int> parents(N);
    int p;
    // 노드의 부모, 자식 관계 저장
    for(int i = 0; i < N; ++i)
    {
        cin >> p;
        parents[i] = p;
        if (p == -1)
            root = i;
        else
    		children[p].push_back(i);
    }

    int target;
    cin >> target;

    queue<int> que;
    que.push(root);
    // 루트부터 트리 순회
    while(false == que.empty())
    {
        int cur = que.front();
        que.pop();

        if (cur == target)
        {
            // cur가 루트 노드가 아니고 부모 노드의 자식이 cur 뿐인 경우,
            // 부모 노드가 leaf 노드가 되므로 카운팅
            if (cur != root && children[parents[cur]].size() == 1)
                ++leafs;
            continue;
        }

        // 자식이 없다면 leaf 노드로 카운팅
        // 있다면 이어서 순회 
        if(children[cur].empty())
            ++leafs;
        else
        {
            for(const int c : children[cur])
                que.push(c);
        }
    }

    cout << leafs;
}