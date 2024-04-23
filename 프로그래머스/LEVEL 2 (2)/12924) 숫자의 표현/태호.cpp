#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> vecInt(n);
    
    for(int i = 0; i < n; ++i)
        vecInt[i] = i + 1;
    
    for(int i = 0; i < n; ++i)
    {
        int sum = 0;
        
        for(int j = i; j < n; ++j)
        {
            sum += vecInt[j];
            if(sum == n)
            {
                ++answer;
            }
            else if(sum > n)
                break;
                
        }
    }
    
    
    return answer;
}
