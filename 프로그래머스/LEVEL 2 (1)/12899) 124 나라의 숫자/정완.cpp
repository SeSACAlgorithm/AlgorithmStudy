// 3진법 응용
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string ans = "";
    char arr[3] = {'4', '1', '2'};
    
    while(n > 0)
    {
        int index_124 = n % 3;
        
        ans += arr[index_124];
        
        n /= 3;
        
        if(index_124 == 0)
            n -= 1;
    }
  
    reverse(ans.begin(), ans.end());
    
    return ans;
}
