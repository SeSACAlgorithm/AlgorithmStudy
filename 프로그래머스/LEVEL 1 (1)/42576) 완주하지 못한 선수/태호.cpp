#include <vector>
#include <unordered_set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_multiset<string> S1;

    for(string& str : completion)
        S1.emplace(str);

    for (string& str : participant)
    {
        auto iter = S1.find(str);
        if (iter == S1.end())
        {
            answer = str;
            break;
        }
        else
            S1.erase(iter);
    }

    return answer;
}
