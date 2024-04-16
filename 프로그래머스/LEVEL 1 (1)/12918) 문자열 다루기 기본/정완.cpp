#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool ans = true;
    
    if(s.size() != 4 && s.size() != 6)
        return false;
    
    
    for(char c:s)
        if(isdigit(c) == false)
            return false;
    
    
    return ans;
}
