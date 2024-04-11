#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    
    for( int i=0; i<s.size(); i++)
    {
        if(s[i] == ' ')
            continue;
        
        for(int j=0; j<n; j++)
        {
            if(s[i] == 'z' || s[i] == 'Z')
            {
                s[i] -= 25;
                continue;
            }
            
            s[i]++;
        }
    }
    return s;
}
