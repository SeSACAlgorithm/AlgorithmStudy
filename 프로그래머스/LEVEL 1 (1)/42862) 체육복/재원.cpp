
//손실 먼저 계산후 채우는 방식
//1.5명의 정보를 담을 배열 생성 체육복 있으면 0 하나 더있으면 1 없으면 -1  1,1,1,1,1
//2.없는 인덱스 -1으로변환
//3. 채울때 자신의 체육복 유무 먼저 확인
//4. 그후
#include <string>
#include <vector>

using namespace std;

int student[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    for(int i = 0; i < lost.size(); i++){
        student[lost[i]]--;
    }
    
    for(int i = 0; i < reserve.size(); i++){
        student[reserve[i]]++;
    }
    
    for(int i = 1; i <= n; i++){
        if(student[i] == -1){
            if(student[i - 1] == 1){
                student[i - 1] = 0;
                student[i] = 0;
            }
            else if(student[i + 1] == 1){
                student[i + 1] = 0;
                student[i] = 0;
            }
        }   
            
        if(student[i] >= 0) answer++;
    }
    
    return answer;
}
