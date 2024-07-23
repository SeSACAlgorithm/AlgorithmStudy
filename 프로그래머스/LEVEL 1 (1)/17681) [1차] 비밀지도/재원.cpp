#include <string>
#include <vector>
#include <bitset>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
        for (int i = 0; i < n; ++i) {
        // arr1[i]와 arr2[i]를 각각 이진수로 변환
        bitset<16> bs1(arr1[i]);
        bitset<16> bs2(arr2[i]);
        
        // 이진수를 문자열로 변환하여 비트 연산 후 결과를 문자열로 저장
        string line = "";
        for (int j = n - 1; j >= 0; --j) {
            if (bs1[j] || bs2[j]) {
                line += '#';
            } else {
                line += ' ';
            }
        }
        
        // 결과를 answer에 추가 /배열형 string은 push.pack 을 사용한다 
        answer.push_back(line);
          
    }

    return answer;
}
//1. arr1 과 arr2를 이진수 변환하여 bs1배열,bs2배열에 위치는 그대로 하여 변환한다
//2.변환된 도표를 문제의 조건에 맞게 1이 하나라도 있으면 비밀지도 위치는 1 , 두개다 0 이면 비밀지도도 0으로 계산한다 

// 이진수 변환은 bitset 함수를 이용한다
//2. 2중배열을 사용하여 한번에 처리한다


