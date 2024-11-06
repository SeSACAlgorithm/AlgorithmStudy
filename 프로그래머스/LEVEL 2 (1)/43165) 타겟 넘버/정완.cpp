#include <string>
#include <vector>

using namespace std;

int ans = 0;

void recursion(vector<int> numbers, int target, int sum, int index){
    if(index == numbers.size())
    {
        if(sum == target)   // 조건 충족할 경우에만 ans++
            ans++;
        
        return;
    }
    
    recursion(numbers, target, sum + numbers[index], index + 1);    // 재귀
    recursion(numbers, target, sum - numbers[index], index + 1);    // 재귀
    
}

int solution(vector<int> numbers, int target) {
    recursion(numbers, target, 0, 0);
    
    return ans;
}
