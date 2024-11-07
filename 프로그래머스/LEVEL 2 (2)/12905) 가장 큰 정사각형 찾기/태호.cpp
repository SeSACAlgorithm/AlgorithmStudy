#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calu_squre(int i, int j, const vector<vector<int>>& board)
{
    return min({board[i - 1][j - 1], board[i - 1][j], board[i][j - 1]}) + 1;
}

int solution(vector<vector<int>> board)
{
    int answer = 0;

    int n = board.size();
    int m = board[0].size();
    
    for(int i = 1; i < n; ++i)
        for(int j = 1; j < m; ++j)
            if(board[i][j])
                board[i][j] = calu_squre(i, j, board);
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            answer = max(answer, board[i][j]);


    return answer * answer;
}
