#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    string tmp = "";
    
    vector<int> vecInt;
    
    for (char c : s)
    {
        if(c != ' ')
        {
            tmp += c;
        }
        else
        {
            vecInt.push_back(stoi(tmp));
            tmp = "";
        }
    }
    
    vecInt.push_back(stoi(tmp));
    
    sort(vecInt.begin(), vecInt.end());
    
    answer += to_string(vecInt.front()) + " " + to_string(vecInt.back());


    return answer;
}
