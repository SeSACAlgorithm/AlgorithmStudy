#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int bef = -1;
    for(int n : arr)
    {
        if(n == bef) continue;
        
        answer.push_back(n);
        bef = n;
    }
    return answer;
}