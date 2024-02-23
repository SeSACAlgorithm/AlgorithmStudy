#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    int n1 = 0, n2 = 0;
    for(int i = 0; i < n; i++)
    {
        string s = "";
        n1 = arr1[i] | arr2[i];
        for(int j = n - 1; j >= 0; j--)
        {
            n2 = (n1 >> j) & 1;
            s += n2 ? "#" : " ";
        }
        answer.push_back(s);
    }
    
    return answer;
}