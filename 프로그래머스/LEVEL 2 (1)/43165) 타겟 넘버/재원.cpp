#include <vector>

using namespace std;

void dfs(const vector<int>& numbers, int target, int index, int currentSum, int& answer) {
    // 
    if (index == numbers.size()) {
        if (currentSum == target) {
            answer++; //모든순환이 끝나고 결과 총합이 target과 같으면 answer++
        }
        return;
    }
    
    //index가 1씩 늘고 현재 총합에index의 -와 + 를각각더하는 재귀함수 
    dfs(numbers, target, index + 1, currentSum + numbers[index], answer);
    dfs(numbers, target, index + 1, currentSum - numbers[index], answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, target, 0, 0, answer);
    return answer;
}
