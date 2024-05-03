#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    
    while(n>0)
    {
        n%2 == 1 ? ans++ : ans;
        n /=2;
    }
    
    return ans;
}
