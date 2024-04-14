#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> numbers)
{
    string answer = "";

    sort(numbers.begin(), numbers.end(), [](int num1, int num2)
        {
            string A = to_string(num1), B = to_string(num2);
            return A + B > B + A;
        });
    
    if(numbers[0] == 0)
        return "0";
    
    for(int i = 0; i < numbers.size(); ++i)
        answer += to_string(numbers[i]);

    return answer;
}
