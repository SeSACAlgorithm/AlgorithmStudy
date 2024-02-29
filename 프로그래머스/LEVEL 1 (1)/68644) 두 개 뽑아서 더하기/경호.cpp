#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    map<int, bool> checked;
    
    int sum = 0;
    for(int i = 0; i < numbers.size(); i++)
    {
        for(int j = i + 1; j < numbers.size(); j++)
        {
            sum = numbers[i] + numbers[j];
            if(checked[sum])
                continue;
            
            answer.push_back(sum);
            checked[sum] = true;
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}