#include <string>
#include <vector>
#include <bitset>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i=0; i<n; i++)
    {
        bitset<16> bit(arr1[i] | arr2[i]);
        string map = bit.to_string();
        string ans = "";
        
        for(int j=16-n; j<map.size(); j++)
        {
            if(map[j] == '1')
                ans += '#';

            else
                ans += ' ';
        }
        
        answer.push_back(ans);
    }
    return answer;
}
