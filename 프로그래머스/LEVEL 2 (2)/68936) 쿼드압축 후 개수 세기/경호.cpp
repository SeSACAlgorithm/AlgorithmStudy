#include <vector>

using namespace std;

void compress(vector<vector<int>>& arr, vector<int>& answer, int begin_x, int begin_y, int len)
{
    int initial = arr[begin_y][begin_x];
    bool equal = true;
    for(int i = 0; i < len; ++i)
    {
        for(int j = 0; j < len; ++j)
        {
            if(arr[begin_y + i][begin_x + j] != initial)
            {
                equal = false;
                break;
            }
        }
        if(false == equal)
            break;
    }
    if(equal)
    {
        ++answer[initial];
        return;
    }
        
    int new_len = len >> 1;
    compress(arr, answer, begin_x, begin_y, new_len);
    compress(arr, answer, begin_x + new_len, begin_y, new_len);
    compress(arr, answer, begin_x, begin_y + new_len, new_len);
    compress(arr, answer, begin_x + new_len, begin_y + new_len, new_len);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    compress(arr, answer, 0, 0, arr.size());
    
    return answer;
}