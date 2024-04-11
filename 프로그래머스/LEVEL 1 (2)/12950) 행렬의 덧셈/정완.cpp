#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> ans;
    int add;
    
    for(int i = 0; i < arr1.size(); i++)
    {
        vector<int> num;
        for(int j = 0; j < arr2[i].size(); j++)
        {
            add = arr1[i][j] + arr2[i][j];
            num.push_back(add);
        }
        ans.push_back(num);
    }
    
    return ans;
}
