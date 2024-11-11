#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> freq;
    
    for(int i = 0; i < clothes.size(); ++i)
        ++freq[clothes[i][1]];
    
    for(auto iter : freq)
        answer *= (iter.second + 1);

    
    return answer - 1;
}
