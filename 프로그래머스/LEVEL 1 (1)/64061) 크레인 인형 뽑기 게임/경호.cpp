#include <vector>
#include <stack>
#include <map>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    map<int, int> idxes;
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            if(board[j][i] == 0) continue;
                
            idxes[i] = j;
            break;
        }
    }
    
    
    stack<int> basket;
    int idx = 0;
    for(int n : moves)
    {
        idx = idxes[n - 1];
        // 인형이 없는 경우
        if(idx == board.size()) continue;
        
        // 인형을 뽑는 경우
        int last = basket.empty() ? -1 : basket.top();
        int item = board[idx][n - 1];
        if(last == item)
        {
            basket.pop();
            answer++;
        }
        else
            basket.push(item);
        
        idxes[n - 1]++;
    }
    
    return answer * 2;
}