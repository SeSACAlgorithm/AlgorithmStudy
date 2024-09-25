#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 좌표 90도 회전
void rotate_clockwise(const vector<pair<int,int>>& origin, vector<pair<int,int>>& target, int n)
{
    for(int i = 0; i < origin.size(); ++i)
        target[i] = pair<int,int>{ origin[i].second, n - 1 - origin[i].first };
    // 좌표 정렬 기준 유지
    sort(target.begin(), target.end());
}

bool check_puzzle(const vector<pair<int,int>>& hole, const vector<pair<int,int>>& piece)
{
    // 첫번째 좌표를 이용해 offset 계산
    int y_offset = hole[0].first - piece[0].first;
    int x_offset = hole[0].second - piece[0].second;
    // 두번째 좌표부터 검사하여 offset이 동일하게 나오지 않는다면 false 반환
    for(int i = 1; i < hole.size(); ++i)
    {
        if(hole[i].first - piece[i].first != y_offset)
            return false;
        if(hole[i].second - piece[i].second != x_offset)
            return false;
    }
    // 전부 통과했다면 true 반환
    return true;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    int n = static_cast<int>(game_board.size());
    
    // 게임 보드에서 홈 찾기(BFS)
    vector<vector<pair<int,int>>> holes;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(visited[i][j]) continue;
            visited[i][j] = true;
            if(1 == game_board[i][j]) continue;
            
            vector<pair<int,int>> points;
            queue<pair<int, int>> que;
            que.emplace(i, j);
            while(false == que.empty())
            {
                int y = que.front().first;
                int x = que.front().second;
                points.emplace_back(y, x);
                que.pop();

                if(y - 1 >= 0 && 0 == game_board[y - 1][x] && false == visited[y - 1][x])
                {
                    visited[y - 1][x] = true;
                    que.emplace(y - 1, x);
                }
                if(x - 1 >= 0 && 0 == game_board[y][x - 1] && false == visited[y][x - 1])
                {
                    visited[y][x - 1] = true;
                    que.emplace(y, x - 1);
                }
                if(y + 1 < n && 0 == game_board[y + 1][x] && false == visited[y + 1][x])
                {
                    visited[y + 1][x] = true;
                    que.emplace(y + 1, x);
                }
                if(x + 1 < n && 0 == game_board[y][x + 1] && false == visited[y][x + 1])
                {
                    visited[y][x + 1] = true;
                    que.emplace(y, x + 1);
                }
            }
            sort(points.begin(), points.end());
            holes.push_back(points);
        }
    }
    // 내림차순 정렬
    sort(holes.begin(), holes.end(), [](vector<pair<int,int>> a, vector<pair<int,int>> b) { 
        return a.size() > b.size(); });
    
    // 테이블에서 조각 찾기(BFS)
    vector<vector<pair<int,int>>> pieces_0;
    vector<vector<bool>> used(n, vector<bool>(n, false));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(used[i][j]) continue;
            used[i][j] = true;
            if(0 == table[i][j]) continue;
            
            vector<pair<int,int>> points;
            queue<pair<int, int>> que;
            que.emplace(i, j);
            while(false == que.empty())
            {
                int y = que.front().first;
                int x = que.front().second;
                points.emplace_back(y, x);
                que.pop();

                if(y - 1 >= 0 && 1 == table[y - 1][x] && false == used[y - 1][x])
                {
                    used[y - 1][x] = true;
                    que.emplace(y - 1, x);
                }
                if(x - 1 >= 0 && 1 == table[y][x - 1] && false == used[y][x - 1])
                {
                    used[y][x - 1] = true;
                    que.emplace(y, x - 1);
                }
                if(y + 1 < n && 1 == table[y + 1][x] && false == used[y + 1][x])
                {
                    used[y + 1][x] = true;
                    que.emplace(y + 1, x);
                }
                if(x + 1 < n && 1 == table[y][x + 1] && false == used[y][x + 1])
                {
                    used[y][x + 1] = true;
                    que.emplace(y, x + 1);
                }
            }
            sort(points.begin(), points.end());
            pieces_0.push_back(points);
        }
    }
    // 내림차순 정렬
    sort(pieces_0.begin(), pieces_0.end(), [](vector<pair<int,int>> a, vector<pair<int,int>> b) { 
        return a.size() > b.size(); });
    
    int total_pieces = static_cast<int>(pieces_0.size());
    // 90도 회전
    vector<vector<pair<int,int>>> pieces_90;
    for(const vector<pair<int,int>> origin : pieces_0)
    {
        vector<pair<int,int>> target(origin.size());
        rotate_clockwise(origin, target, n);
        pieces_90.push_back(target);
    }
    // 180도 회전
    vector<vector<pair<int,int>>> pieces_180;
    for(const vector<pair<int,int>> origin : pieces_90)
    {
        vector<pair<int,int>> target(origin.size());
        rotate_clockwise(origin, target, n);
        pieces_180.push_back(target);
    }
    // 270도 회전
    vector<vector<pair<int,int>>> pieces_270;
    for(const vector<pair<int,int>> origin : pieces_180)
    {
        vector<pair<int,int>> target(origin.size());
        rotate_clockwise(origin, target, n);
        pieces_270.push_back(target);
    }
    
    // 테이블의 조각마다 게임보드의 홈에 끼울 수 있는지 검사
    vector<bool> complete(holes.size(), false);
    int h_idx = 0;
    int p_idx = 0;
    while(p_idx < total_pieces)
    {
        // 마지막 홈까지 검사했는데 만족하지 않은 경우
        // 홈 인덱스 초기화 및 조각 인덱스 증가
        if(h_idx == holes.size())
        {
            h_idx = 0;
            ++p_idx; 
            continue;
        }
        // 이미 끼운 홈이라면 패스
        if(complete[h_idx])
        {
            ++h_idx;
            continue;
        }
        // 홈의 크기가 조각의 크기보다 크다면 패스
        if(holes[h_idx].size() > pieces_0[p_idx].size())
        {
            ++h_idx; 
            continue;
        }
        // 홈과 조각 모두 내림차순 정렬했으므로,
        // 조각의 크기가 홈의 크기보다 크다면 맞는 홈이 없는 것
        // => 홈 인덱스 초기화 및 조각 인덱스 증가
        if(holes[h_idx].size() < pieces_0[p_idx].size())
        {
            h_idx = 0; 
            ++p_idx;
            continue;
        }
        
        bool success = check_puzzle(holes[h_idx], pieces_0[p_idx]) 
                       || check_puzzle(holes[h_idx], pieces_90[p_idx]) 
                       || check_puzzle(holes[h_idx], pieces_180[p_idx]) 
                       || check_puzzle(holes[h_idx], pieces_270[p_idx]);
        
        // 4가지 회전 조각 모두 검사하여 하나라도 성공했다면
        // 조각 크기만큼 정답 카운팅 및 완료 벡터에 기록
        // 홈 인덱스 초기화 및 조각 인덱스 증가
        if(success)
        {
            answer += pieces_0[p_idx].size();
            complete[h_idx] = true;
            h_idx = 0;
            ++p_idx;
        }
        else
            ++h_idx;
    }
    
    return answer;
}