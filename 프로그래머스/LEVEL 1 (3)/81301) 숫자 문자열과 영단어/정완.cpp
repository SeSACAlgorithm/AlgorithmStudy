#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int ans = 0;
    string tmp = "";
    vector<string> arr = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    for(auto c : s)
    {
        if (isdigit(c)) // 숫자면
            ans = ans * 10 + c - '0';
        
        else            // 문자면
            tmp.push_back(c);

        for(int i=0; i<10; i++)
        {
            if (arr[i] == tmp)
            {
                ans = ans * 10 + i;
                tmp = "";           // 초기화
                break ;
            }
        }
    }
    return ans;
}
