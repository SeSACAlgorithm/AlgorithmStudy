#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int ans = 0;
    long n = num;
    
    while(n != 1)
    {
        ans++;
        n = n%2 == 0 ? n/2 : n*3+1;
        
        if(ans >=500)
        {
            return -1;
            break;
        }
    }
    return ans;
}
