#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string str1, string str2)
{
    return (str1 + str2) > (str2 + str1);
}

string solution(vector<int> numbers) {
    vector<string> v_str_numbers;
    string answer = "";

    // 문자열로 바꾸기
    for(int i = 0; i < numbers.size(); i++)
    {
        v_str_numbers.push_back(to_string(numbers[i]));
    }

    // 조건대로 정렬
    sort(v_str_numbers.begin(), v_str_numbers.end(), compare);
    
    if(v_str_numbers[0] == "0") return "0";

    for(int i = 0; i < v_str_numbers.size(); i++)
    {
        answer += v_str_numbers[i];
    }

    return answer;
}