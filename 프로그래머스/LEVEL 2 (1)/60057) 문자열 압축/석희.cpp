#include <string>
#include <algorithm>

using namespace std;

// 자를 길이, 문자열
string TransStr(int standard, string s)
{
    if (standard == 0) return s;

    string temp = "";
    string last = "";
    string result = "";

    int count = 1;              // 같은 문자열이 몇개 나왔는지
    int temp_index = 0;         // 문자열 자를 때 어디까지 확인했는지

    int i = 0;
    while(i < s.length())
    {
        // 기준만큼 문자열 자르기 (substr도 사용 가능)
        temp_index = 0;
        while (temp_index != standard)
        {
            temp += s[i];
            i++;
            temp_index++;

            if (i >= s.length()) break;
        }

        if (last == temp) count++;
        else
        {
            if (last != "")
            {
                result += count == 1 ? last : to_string(count) + last;
                count = 1;
            }
        }
        
        last = temp;
        temp = "";
    }

    result += count == 1 ? last : to_string(count) + last;
    return result;
}

int solution(string s)
{
    int answer = 987654321;

    int range = s.length() / 2;
    for (int i = 0; i <= range; i++)
    {
        string trans_str = TransStr(i, s);
        answer = min(answer, (int)trans_str.length());
    }
    return answer;
}