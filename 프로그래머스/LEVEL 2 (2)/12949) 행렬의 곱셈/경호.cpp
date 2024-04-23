#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size(), 0));
    
    for(int row1 = 0; row1 < arr1.size(); ++row1)
    {
        for(int col2 = 0; col2 < arr2[0].size(); ++col2)
        {
            int sum = 0;
            for(int row2 = 0; row2 < arr2.size(); ++row2)
            {
                sum += arr1[row1][row2] * arr2[row2][col2];
            }
            answer[row1][col2] = sum;
        }
    }
    
    return answer;
}