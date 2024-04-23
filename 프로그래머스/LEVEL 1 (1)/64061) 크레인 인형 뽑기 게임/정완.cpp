#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int ans = 0;
    stack<int> basket;
    
    for(int i=0; i<moves.size(); i++)
    {
        int tmp = moves[i] - 1;
        
        for(int j=0; j<board[0].size(); j++)
        {
            if(board[j][tmp] != 0)
            {
                if(!basket.empty() && basket.top() == board[j][tmp])
                {
                    basket.pop();
                    board[j][tmp]=0;
                    ans += 2;
                }
                
                else
                {
                    basket.push(board[j][tmp]);
                    board[j][tmp]=0;
                }
                
                break;
            }
        }
    }
    return ans;
}
