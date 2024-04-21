#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    stack<int> baskets;
    
    int n = board.size();
    int m = board[0].size();
    
    for(int k = 0; k < moves.size(); k++){
        // 뽑은 인형의 열 숫자
        int tmp = moves[k] - 1;
        
        // 행 count
        for(int i = 0 ; i < n; i++){
            if(board[i][tmp] != 0){
                if(!baskets.empty() && board[i][tmp] == baskets.top()){
                    baskets.pop();
                    board[i][tmp] = 0;
                    // 인형은 2개씩 사라짐 -> 문제는 사라진 인형의 갯수 출력
                    answer+=2;
                } else {
                    baskets.push(board[i][tmp]);
                    board[i][tmp] = 0;
                }   
                break;
            }
        }
    }
    
    
    return answer;
}
