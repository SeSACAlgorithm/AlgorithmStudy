#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> ans;
    ans.push_back(arr[0]);
        for(int i=1; i<arr.size(); i++)
        {
            if(ans.back() != arr[i])
            {
                ans.push_back(arr[i]);
            }
        }
    return ans;
}
