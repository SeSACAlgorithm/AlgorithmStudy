#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
 for(int i = 0; i < commands.size(); i++) {
     
        // commands 시작, 끝, 결과 인덱스를 각각 변수로 저장
        int start = commands[i][0] - 1; // 0 기반 인덱스로 변환위해 -1
        int end = commands[i][1];       // 끝 인덱스
        int ans = commands[i][2] - 1;   // 0 기반 인덱스로 변환위해 -1
        
        vector<int> arr; // 부분 배열을 저장할 벡터
        
        // array의 start부터 end까지의 요소를 arr에 추가
        for(int j = start; j < end; j++) {
            arr.push_back(array[j]);
        }
        
        // 정렬
        sort(arr.begin(), arr.end());
        
        // 정렬된 배열에서 ans 번째 요소를 answer에 추가
        answer.push_back(arr[ans]);
    }

    return answer;
}
