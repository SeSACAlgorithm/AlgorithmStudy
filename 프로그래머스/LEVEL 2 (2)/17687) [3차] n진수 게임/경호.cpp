#include <string>
#include <vector>

using namespace std;

string get_nbase(int n, int num)
{
    string res = "";
    string digits = "0123456789ABCDEF";
    while(num > 0)
    {
        res = digits[num % n] + res;
        num /= n;
    }
    
    return res;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    int limit = t * m + 1;
    int cur = 0;
    int len = 1;
    int count = 0;
    string value = "0";
    
    int next = p;
    for(int i = 1; i < limit; ++i)
    {
        if(i == next)
        {
            answer += value[count];
            next += m;
        }
        
        ++count;
        if(count == len)
        {
            ++cur;
            value = get_nbase(n, cur);
            len = value.size();
            count = 0;
        }
    }
    
    return answer;
}