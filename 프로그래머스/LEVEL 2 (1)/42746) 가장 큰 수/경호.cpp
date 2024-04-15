#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strs(numbers.size());
    for(int i = 0; i < numbers.size(); i++)
        strs[i] = to_string(numbers[i]);
    
    sort(strs.begin(), strs.end(), [](string a, string b) {
        return a + b > b + a;
    });
    
    if(strs[0] == "0")
        return "0";
    
    for(string s : strs)
        answer.append(s);
    return answer;
}