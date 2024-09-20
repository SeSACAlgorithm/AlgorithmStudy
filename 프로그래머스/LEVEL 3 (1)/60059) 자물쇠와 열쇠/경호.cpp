#include <vector>
#include <queue>
#include <map>

using namespace std;

void rotate_clockwise(const vector<pair<int,int>>& origin, vector<pair<int,int>>& target, int M)
{   
    for(int i = 0; i < origin.size(); ++i)
        target[i] = pair<int,int>{ origin[i].second, M - 1 - origin[i].first };
}

bool lock_check(const vector<vector<int>>& lock, const vector<pair<int,int>>& key, int count, 
                int y_offset, int x_offset)
{
    int N = static_cast<int>(lock.size());
    
    for(const pair<int,int> p : key)
    {
        int y = p.first + y_offset;
        int x = p.second + x_offset;
        if(y < 0 || y >= N) continue;
        if(x < 0 || x >= N) continue;
        
        // 해당 좌표에서 자물쇠도 돌기라면 false
        if(lock[y][x] == 1) return false;
        // 이 외의 경우, 열쇠 홈 카운트 감소
        --count;
    }
    // 카운트가 0이라면 자물쇠를 열 수 있으므로 true, 남아있다면 false
    return count == 0;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int M = static_cast<int>(key.size());
    int N = static_cast<int>(lock.size());
    // 풀어야 하는 열쇠 홈 수 카운팅
    int count = 0;
    for(const vector<int>& vec: lock)
        for(int n : vec)
            if(n == 0)
                ++count;
    
    // 열쇠의 돌기 좌표만 추출한 벡터 생성
    vector<pair<int,int>> key_0;
    for(int i = 0; i < M; ++i)
        for(int j = 0; j < M; ++j)
            if(key[i][j] == 1)
                key_0.emplace_back(i, j);
    
    // 90도씩 회전한 배열 생성
    vector<pair<int,int>> key_90(key_0.size());
    vector<pair<int,int>> key_180(key_0.size());
    vector<pair<int,int>> key_270(key_0.size());
    rotate_clockwise(key_0, key_90, M);
    rotate_clockwise(key_90, key_180, M);
    rotate_clockwise(key_180, key_270, M);
    
    // BFS로 모든 경우의 수 순회
    queue<pair<int, int>> que;
    que.emplace(0, 0);
    map<pair<int,int>, bool> used;
    used[{0, 0}] = true;
    while(false == que.empty())
    {
        int y_offset = que.front().first;
        int x_offset = que.front().second;
        que.pop();
        
        // 4종류의 키에 대해 현재 offset으로 열 수 있는지 체크
        // 하나라도 열 수 있다면 바로 true 반환
        if(lock_check(lock, key_0, count, y_offset, x_offset)) return true;
        if(lock_check(lock, key_90, count, y_offset, x_offset)) return true;
        if(lock_check(lock, key_180, count, y_offset, x_offset)) return true;
        if(lock_check(lock, key_270, count, y_offset, x_offset)) return true;
        
        // 상하좌우로 아직 테스트하지 않은 케이스가 있다면 큐에 추가
        // 단, -N보다는 크고 N보다는 작아야 한다
        if(y_offset - 1 > -N && false == used[{y_offset - 1, x_offset}])
        {
            que.emplace(y_offset - 1, x_offset);
            used[{y_offset - 1, x_offset}] = true;
        }  
        if(x_offset - 1 > -N && false == used[{y_offset, x_offset - 1}]) 
        {
            que.emplace(y_offset, x_offset - 1);
            used[{y_offset, x_offset - 1}] = true;
        }
        if(y_offset + 1 < N && false == used[{y_offset + 1, x_offset}])
        {
            que.emplace(y_offset + 1, x_offset);
            used[{y_offset + 1, x_offset}] = true;
        }  
        if(x_offset + 1 < N && false == used[{y_offset, x_offset + 1}]) 
        {
            que.emplace(y_offset, x_offset + 1);
            used[{y_offset, x_offset + 1}] = true;
        }
    }
    // 열 수 있는 경우가 하나도 없었다면 false 반환
    return false;
}