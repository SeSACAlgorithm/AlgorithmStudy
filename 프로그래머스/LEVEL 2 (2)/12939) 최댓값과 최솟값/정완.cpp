#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string solution(string s) {
    string ans = "";
    string tmp = "";
    
    vector<int> v;
    
    for(auto c : s)
    {
        if(isdigit(c) || c == '-')
            tmp += c;
        
        else if(c == ' ')
        {
            v.push_back(stoi(tmp));
                tmp = "";
        }    
    }
    
    if(!tmp.empty())
        v.push_back(stoi(tmp));
    
    auto minmax = minmax_element(v.begin(), v.end());
    
    ans += to_string(*minmax.first) + " " + to_string(*minmax.second);
    
    return ans;
}
