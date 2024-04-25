#include <string>
#include <vector>

using namespace std;

bool boom[30][30];

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    int dx[3] = {1, 1, 0};
    int dy[3] = {0, -1, -1};

    bool bLoop = true;

    while (true)
    {
        bLoop = false;

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
				        if(board[i][j] == '1') continue;

                bool bSame = true;
                char c = board[i][j];

                for (int dir = 0; dir < 3; ++dir)
                {
                    int nx = dx[dir] + i;
                    int ny = dy[dir] + j;

                    if (nx < 0 || ny < 0 || nx >= m || ny >= n) { bSame = false; break; };
                    if (c != board[nx][ny]) { bSame = false; break; };
                }

                if (bSame)
                {
                    boom[i][j] = true;
                    for (int dir = 0; dir < 3; ++dir)
                    {
                        int nx = dx[dir] + i;
                        int ny = dy[dir] + j;
                        boom[nx][ny] = true;
                    }

                    bLoop = true;
                }
            }
        }

        if(!bLoop)
			      break;

        for (int i = 0; i < board.size(); ++i)
        {
              for (int j = 0; j < board[i].size(); ++j)
              {
                  if(boom[i][j])
                  {
                      boom[i][j] = false;
                      board[i][j] = '1';
                  }
              }
          }


        for (int i = 0; i < board.size(); ++i)
        {
      			for(int j = m - 1; j > 0; --j)
      			{
      
                if(board[j][i] != '1') continue;
                int k = j;
      
                while (k < m)
                {
                    if(board[k][i] != '1')
      						      break;
      
                      swap(board[k][i], board[k - 1][i]);
                      ++k;
                }
      			}
        }
    }

    for(int i = 0; i < board.size(); ++i)
		    for(int j = 0; j < board[i].size(); ++j)
            if(board[i][j] == '1')
				        ++answer;

    return answer;
}
