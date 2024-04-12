#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<stack<int>> S(board.size());
    stack<int> Store;
    
    for (int i = board.size() - 1; i >= 0; --i)
    {
        for (int j = 0; j < board[i].size(); ++j)
        {
            if(board[i][j])
                S[j].push(board[i][j]);
        }
            
    }

    for (int i = 0; i < moves.size(); ++i)
    {
        if(S[moves[i] - 1].empty())
            continue;
        
        Store.push(S[moves[i] - 1].top());
        S[moves[i] - 1].pop();

        while (Store.size() > 1)
        {
            int cur = Store.top(); Store.pop();

            if (Store.top() == cur)
            {
                answer += 2;
                Store.pop();
            }
            else
            {
                Store.push(cur);
                break;
            }
        }
    }

    return answer;
}
