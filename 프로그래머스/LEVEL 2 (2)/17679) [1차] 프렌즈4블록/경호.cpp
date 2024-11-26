#include <string>
#include <vector>

using namespace std;

bool CheckBlocks(vector<string>& board, vector<vector<bool>>& check, int row, int col)
{
    bool crash = false;
    
    for(int i = 0; i <row - 1; i++)
    {
        for(int j = 0; j < col - 1; j++)
        {
            if(board[i][j] == '-') continue;
    
            if(board[i][j] == board[i + 1][j] && board[i][j] == board[i][j + 1] 
               && board[i][j] == board[i + 1][j + 1])
            {
                check[i][j] = true;
                check[i + 1][j] = true;
                check[i][j + 1] = true;
                check[i + 1][j + 1] = true;
                crash = true;
            }
        }
    }
    return crash;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<string> brd;
    for(int i = 0; i < n; i++)
    {
        string temp = "";
        for(int j = 0; j < m; j++)
            temp += board[j][i];
        
        brd.emplace_back(temp);
    }
    vector<vector<bool>> check(n, vector<bool>(m, false));
    
    while(true)
    {
        //블록 파괴 검사, 파괴된 블록이 없을 시 break
        if(CheckBlocks(brd, check, n, m) == false)
            break;
        
        //체크 배열에서 파괴 판정을 받은 블록들 '-'로 변경 및 카운트
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(check[i][j])
                {
                    brd[i].replace(j, 1, "-");
                    answer++;
                }  
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                check[i][j] = false;
        
        //파괴된 블록들 board에서 갱신
        for(int i = 0; i < n; i++)
        {
            string temp = "";
            for(int j = 0; j < m; j++)
            {
                if(brd[i][j] == '-')
                    temp = '-' + temp;
                else
                    temp += brd[i][j];     
            }
            brd[i] = temp;
        }
    }
    
    return answer;
}