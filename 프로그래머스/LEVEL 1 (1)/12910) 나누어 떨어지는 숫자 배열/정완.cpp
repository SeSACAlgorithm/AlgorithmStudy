#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> ans;
   
    for(int i=0; i<arr.size();i++)
        if(arr[i]%divisor == 0)
            ans.push_back(arr[i]);
    
    sort(ans.begin(),ans.end());
    
    if(ans.empty())
        ans.push_back(-1);
    return ans;
}
