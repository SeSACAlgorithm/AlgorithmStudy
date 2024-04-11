#include <vector>

using namespace std;

vector<int> solution(int n, int m){
    vector<int> ans;
    int big = max(n, m);
    int small = min(n, m);
    int multiply = n*m;
    
    // 최대공약수
    for(int i=big; i>0; i--)
    {
        if(n%i == 0 && m%i == 0)
        {
            ans.push_back(i);
            break;
        }
    }
    
    // 최소공배수
    for(int i = big; i<=multiply; i++)
    {
        if(i%big == 0 && i%small == 0)
        {
            ans.push_back(i);
            break;
        }
    }
    
    
    return ans;
}
