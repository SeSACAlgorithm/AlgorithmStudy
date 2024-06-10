#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int sum = 0;
    //배열0번째부터 하나 하나씩 더해보고 결과 answer에 추가
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            sum = numbers[i] + numbers[j];
            answer.push_back(sum);
        }
    }
    // 오름차순 정리
    sort(answer.begin(), answer.end());
    //벡터 중복 제거
    //sort, unique, erase 함수를 활용하여 중복 제거를 할 수 있다.
    //unique 함수는 연속된 중복 원소를 벡터의 가장 뒷부분으로 보내버리는 함수이다. 
    //따라서 unique함수를 실행하기 전에 sort를 통해 정렬되어 있어야하고 unique 실행 후에는 erase를 통해
    //뒷 부분을 삭제해주어야한다.
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    return answer;
}