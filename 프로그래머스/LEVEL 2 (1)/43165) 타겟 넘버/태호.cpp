#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int g_answer = 0;
int g_target = 0;

void target_number(vector<int>& number, int sum = 0, int index = 0)
{
    if(index == number.size())
    {
        if(sum == g_target)
            ++g_answer;
      
        return;
    }

    target_number(number, sum + number[index], index + 1);
    target_number(number, sum - number[index], index + 1);
}

int solution(vector<int> numbers, int target) {
  
    g_target = target;
    target_number(numbers);
    return g_answer;
}
