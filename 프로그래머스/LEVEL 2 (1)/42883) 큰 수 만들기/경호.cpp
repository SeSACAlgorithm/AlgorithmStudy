#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    int idx = 0;
    int a = 0, b = 0;
    bool erased = false;
    while(k > 0)
    {   
        a = number[idx] - '0';
        b = number[idx + 1] - '0';
        
        if(a < b) 
        {
            number.erase(idx, 1);
            k--;
            erased = true;
            idx = 0;
        }
        else
            ++idx;
        
        if(idx == number.size() - 1)
        {
            if(false == erased)
            {
                a = number[idx] - '0';
                b = number[0] - '0';
                if(a <= b)
                {
                    number.erase(idx, 1);
                    k--;
                }
            }
            erased = false;
            idx = 0;
        }
    }
    
    return number;
}