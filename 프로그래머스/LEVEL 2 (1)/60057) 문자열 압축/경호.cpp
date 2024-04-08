#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size();
    
    int idx = 0;
    int lenLimit = s.size() / 2;
    string temp1 = "", temp2 = "";
    for(int len = 1; len <= lenLimit; len++)
    {
        int count = 1, curSize = 0;
        int limit = s.size() - len;
        
        temp1 = s.substr(idx, len);
        idx += len;
        while(idx <= limit)
        {
            temp2 = s.substr(idx, len);
            if(temp1 != temp2)
            {
                curSize += count > 1 ? len + to_string(count).size() : len;
                count = 1;
                temp1 = s.substr(idx, len);
            }
            else
                count++;
            
            idx += len;
        }
        curSize += count > 1 ? len + to_string(count).size() : len;
        curSize += s.size() - idx;
        
        if(curSize < answer)
            answer = curSize;
        
        idx = 0;
    }
    return answer;
}