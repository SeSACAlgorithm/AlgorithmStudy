#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string ans = "";
    
    int left = 10;  // 왼손 시작 위치
    int right = 12; // 오른손 시작 위치
    
    for(int i=0; i<numbers.size(); i++)
    {
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)   // 왼손 영역인 경우
        {
            ans += "L";
            left = numbers[i];
        }
        
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)  // 오른손 영역인 경우
        {
            ans += "R";
            right = numbers[i];
        }
        
        else    // 0인 경우
        {
            if(numbers[i] == 0)
                numbers[i] = 11;
            
            // 세로 + 가로 --> 절대값으로
            int leftlen = abs(numbers[i] - left) / 3 + abs(numbers[i] - left) % 3;
            int rightlen = abs(numbers[i] - right) / 3 + abs(numbers[i] - right) % 3;
            
            if(leftlen > rightlen)
            {
                ans += "R";
                right = numbers[i];
            }
            
            else if(leftlen < rightlen)
            {
                ans += "L";
                left = numbers[i];
            }
            
            else    // 거리가 같은 경우 왼손잡이 or 오른손잡이
            {
                if(hand == "left")
                {
                    ans += "L";
                    left = numbers[i];
                }
                
                else
                {
                    ans += "R";
                    right = numbers[i];
                }
            }
        }
    }
    
    return ans;
}
