#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    // 학생 수 만큼의 벡터 만들기 -> 모두 체육복 있다고 가정, 1로 초기화
    int student[n];
    for(int i = 0; i < n; i++) {
        student[i] = 1;
    }
    // array대신 vector 사용 가능하네 오우 이 경우 n대신 student.size 사용가능함 이게 더 나은듯
    // vector는 동적으로 크기 조절이 가능!! vector쓰고 size쓰는게 좋은 듯? 흠?
    // vector<int> student(n,1);
    // lost학생은 0으로 , 0기반 인덱스로 변환위해 -1 
    for(int i=0;i<lost.size();i++){
        student[lost[i]-1]--;
    }
    // reserve학생 2로, 0기반 -1
    for(int i=0;i<reserve.size();i++){
        student[reserve[i]-1]++;
    }
    //student 돌면서 체육복 빌려주자!
    for(int i=0;i<n;i++){
        // lost 학생이면 -> 0이라면
        if(student[i]==0){
             // 1. 앞 번호가 빌려주는 경우, 앞 번호가 없으면 제외해주기!!!!
            if(i!=0&&student[i-1]==2){
                student[i]++; // 받은 학생 +1
                student[i-1]--; // 빌려준 학생 -1
            }
            // 2. 뒷 번호가 빌려주는 경우, 뒷 번호가 없으면 제외!!
            else if(i!=(n-1)&&student[i+1]==2){
                student[i]++; 
                student[i+1]--; 
            }
        }
    }
    // 이제 학생들 확인해서 체육복있으면 -> 0이 아니라면 answer++
    for(int i=0;i<n;i++){
        if(student[i]!=0)
            answer++;
    }
    return answer;
}
