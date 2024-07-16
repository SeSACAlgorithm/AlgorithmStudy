#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// 전위 순회: 루트 노드 -> 좌측 서브트리 -> 우측 서브트리
// 후위 순회: 좌측 서브트리 -> 우측 서버트리 -> 루트 노드
void pre_and_post(const vector<vector<int>>& nodeinfo, vector<vector<int>>& answer, 
               map<int, int>& numbers, int start, int end)
{
    if(start >= end) return;
    
    int root_idx = 0;
    int max_y = -1;
    for(int i = start; i < end; ++i)
    {
        if(nodeinfo[i][1] > max_y)
        {
            max_y = nodeinfo[i][1];
            root_idx = i;
        }
    }
    
    answer[0].emplace_back(numbers[nodeinfo[root_idx][0]]);
    pre_and_post(nodeinfo, answer, numbers, start, root_idx);
    pre_and_post(nodeinfo, answer, numbers, root_idx + 1, end);
    answer[1].emplace_back(numbers[nodeinfo[root_idx][0]]);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2, vector<int>(0));
    
    // 노드 번호 저장
    map<int, int> numbers;
    for(int i = 0; i < nodeinfo.size(); ++i)
        numbers.insert({nodeinfo[i][0], i + 1});
    
    // x좌표 기준 정렬
    sort(nodeinfo.begin(), nodeinfo.end(), [](vector<int> a, vector<int> b){
        return a[0] < b[0];
    });
    
    pre_and_post(nodeinfo, answer, numbers, 0, nodeinfo.size());
    return answer;
}