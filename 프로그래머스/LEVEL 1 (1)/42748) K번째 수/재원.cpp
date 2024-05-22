#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//1. commands값을 계산하기위해 각각 들어오는 i,j,k 값대로 배열만들기 
//2. 만든 배열을 정렬하고 
//3. k번쨰 수를 추출 
//4. 반복


vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    int count = 0;
    
    for(int i=0;i<commands.size();i++)
    {
        int start = commands[i][0]-1;
        int end = commands[i][1];
        int need = commands[i][2]-1;
     
        vector<int> temp(array.begin() + start, array.begin() + end) ;
            
        sort(temp.begin(), temp.end());
        
        answer.push_back(temp[need]);
        
    } 
    return answer;
}
