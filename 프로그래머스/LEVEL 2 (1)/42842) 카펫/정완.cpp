#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> ans;
    
    int carpet = brown + yellow;
    int w = 0;
    
    for(int h=3; h<=carpet; h++)
    {
        if(carpet % h == 0)
        {
            w = carpet / h;
            
            if((w - 2) * (h - 2) == yellow)
            {
                ans.push_back(w);
                ans.push_back(h);
                break;
            }
        }
    }
    return ans;
}
