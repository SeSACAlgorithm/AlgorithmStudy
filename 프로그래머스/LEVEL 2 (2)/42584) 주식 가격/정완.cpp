#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> ans;
    
    for(int i=0; i<prices.size(); i++)
    {
        int time = 0;   // 떨어지지 않은 기간 초기화
    
        for(int j=i+1; j<prices.size(); j++)
        {
            time++;
            
            if(prices[i] > prices[j])
                break;
        }
        
        ans.push_back(time);
    }
    return ans;
}
