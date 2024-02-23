#include <string>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    
    for(int i =0; i <commands.size(); i++){
        vector<int> tmp;
        for(int j = commands[i][0]-1; j <commands[i][1]; j++){
            tmp.push_back(array[j]);
            
        }
        sort(tmp.begin(), tmp.end());
        int a = commands[i][2];
        answer.push_back(tmp[a-1]);
    }
    
    return answer;
}