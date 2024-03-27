#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> wear;
    
    vector<string> keys;
    for(vector<string> vec : clothes)
    {
        wear[vec[1]]++;
        // 새로운 키라면 keys에 등록
        if(wear[vec[1]] == 1)
            keys.push_back(vec[1]);
    }
    
    int answer = 1;
    for(string key : keys)
        answer *= wear[key] + 1;
    
    return answer - 1;
}