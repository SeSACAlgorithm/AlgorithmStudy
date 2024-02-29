#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs)
{
    int ans = 0;
    int result;
    
    for(int i=0; i<absolutes.size(); i++)
    {
        if(signs[i])
        {
            result = absolutes[i];
        }
        
        else
        {
            result = -absolutes[i];
        }
        ans += result;
    }
    return ans;
}
