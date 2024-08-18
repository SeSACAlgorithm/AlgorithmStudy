#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s)
{
    int n = s.size();
    int min_length = n;
    
    for (int i=1; i<=n/2; ++i)
    {
        string comp;
        string prev = s.substr(0, i);
        int cnt = 1;    // 반복 문자(열) 카운트

        for (int j=i; j<n; j+=i)
        {
            string cur = s.substr(j, i);
            
            if (cur == prev)
                cnt++;
            
            else
            {
                if (cnt > 1)
                    comp += to_string(cnt);
                
                comp += prev;
                prev = cur;
                cnt = 1;
            }
        }
        
        if (cnt > 1)
            comp += to_string(cnt);     // (1) 문자열 개수
        
        comp += prev;   // (2) 반복된 문자열

        min_length = min(min_length, (int)comp.size());
    }
    
    return min_length;
}
