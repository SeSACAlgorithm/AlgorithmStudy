#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i = 0; i < commands.size(); ++i)
    {
        int sour = commands[i][0];
        int dest = commands[i][1];
        int k = commands[i][2];
        
        vector<int> vec;
            
        for(int j = sour - 1; j < dest; ++j)
            vec.push_back(array[j]);
        
         sort(vec.begin(), vec.end());
        
        answer.push_back(vec[k - 1]);
    }
    
    return answer;
}
