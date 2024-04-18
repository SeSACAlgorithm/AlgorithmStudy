#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int R = 12;
    int L = 10;
    
    for (int i = 0 ; i < numbers.size(); i++){
        if(numbers[i] == 0) numbers[i] = 11;
        
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7 ){
            answer += 'L';
            L = numbers[i];
        } else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9 ){
            answer += 'R';
            R = numbers[i];
        } else {
            
            // 왼손과 오른손에서 숫자까지의 거리 계산
            int distL = abs((L-1) / 3 - (numbers[i]-1) / 3) + abs((L-1) % 3 - (numbers[i]-1) % 3);
            int distR = abs((R-1) / 3 - (numbers[i]-1) / 3) + abs((R-1) % 3 - (numbers[i]-1) % 3);
            
            if(distL == distR){
                if(hand == "right"){
                    answer += 'R';
                    R = numbers[i];
                } else {
                    answer += 'L';
                    L = numbers[i];
                }
            }
            
            if( distL > distR ){
                answer += 'R';
                R = numbers[i];
            } 
            
            if( distL < distR ){
                answer += 'L';
                L = numbers[i];
            }
    
        }
    }
    
    return answer;
}
