#include <string>
#include <vector>
#include <stack>

using namespace std;

int find_top(vector<vector<int>> board, int move)
{
    for (int i = 0; i < board.size(); i++)
    {
        if (board[i][move - 1] != 0)
            return i;
    }
    return -1;
}

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    int basket_top = -1;
    stack<int> s_basket;

    for (int move : moves)
    {
        // 선택한 칸의 인형 있는 인덱스 확인
        int board_top = find_top(board, move);
        if (board_top == -1)
            continue;

        // 인형 번호 확인
        int grab_doll = board[board_top][move - 1];
        board[board_top][move - 1] = 0;

        // 바구니가 비어있다면
        if (s_basket.empty())
            basket_top = -1;
        // 비어있지 않다면 top 빼기
        else
            basket_top = s_basket.top();

        // top과 방금 넣는 인형이 같다면
        if (basket_top == grab_doll)
        {
            answer++;
            s_basket.pop();
        }
        // 다르면 바구니에 넣기
        else
            s_basket.push(grab_doll);
    }

    return answer * 2;
}
