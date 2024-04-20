#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(string s) {
    int count = 0;
    int erased = 0;
    
    string temp = "";
    while(s != "1")
    {
        // 0 제거
        for(int i = s.size() - 1; i >= 0; --i)
        {
            if(s[i] == '0')
            {
                s.erase(s.begin() + i);
                ++erased;
            }
        }
            
        
        // 변환
        int len = s.size();
        while(len > 0)
        {
            temp += to_string(len % 2);
            len /= 2;
        }
        
        s = temp;
        temp = "";
        ++count;
    }
    
    return vector<int>{count, erased};
}