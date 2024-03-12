#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    queue<pair<int, int>> que;
    que.push(pair<int, int>(1, numbers[0]));
    que.push(pair<int, int>(1, -numbers[0]));
    
    pair<int, int> cur;
    while(false == que.empty())
    {
        cur = que.front();
        que.pop();
        // 모두 더한 값이라면 타겟과 같은지 체크
        if(cur.first == numbers.size())
        {
            if(cur.second == target)
                answer++;
            continue;
        }
        // +- 각각 추가
        int nextIdx = cur.first + 1;
        int nextVal = numbers[cur.first];
        que.push(pair<int, int>(nextIdx, cur.second + nextVal));
        que.push(pair<int, int>(nextIdx, cur.second - nextVal));
    }
    return answer;
}