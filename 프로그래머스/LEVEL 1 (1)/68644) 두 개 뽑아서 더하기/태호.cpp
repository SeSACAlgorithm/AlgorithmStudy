#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    set<int> answer;
    
    for(int i = 0; i < numbers.size(); ++i)
	    for(int j = i + 1; j < numbers.size(); ++j)
            answer.emplace(numbers[i] + numbers[j]);

    return vector<int>(answer.begin(), answer.end());
}
