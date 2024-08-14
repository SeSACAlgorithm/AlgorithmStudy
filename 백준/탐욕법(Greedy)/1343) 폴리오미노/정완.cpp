/*

XXXX -> AAAA
XX   -> BB
.    -> .

*/

#include "iostream"

using namespace std;

int main()
{
    string board, result;
    int cnt = 0;

    cin >> board;

    board += ' ';

    for(int i=0; i<board.size() - 1; i++)
    {
        if(board[i] == 'X')
            cnt++;

        if(cnt == 4)    // AAAA 인 경우
        {
            result += "AAAA";
            cnt = 0;
        }

        if(cnt == 2 && board[i+1] != 'X')   // BB 인 경우
        {
            result += "BB";
            cnt = 0;
        }

        if(board[i] == '.') // . 인 경우 (덮으면 안 되는 경우)
        {
            result += '.';

            if(cnt % 2 != 0)
                break;
            
            else
                cnt = 0;
        }
    }

    if(cnt % 2 == 1)    // 덮어쓰지 못 한 경우
        cout << -1;
    
    else
        cout << result;
}