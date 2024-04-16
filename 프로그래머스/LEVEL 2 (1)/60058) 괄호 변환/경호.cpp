#include <string>

using namespace std;

bool correct(const string& str)
{
    int l = 0, r = 0;
    for(int i = 0; i < str.size(); ++i)
    {
        if(str[i] == '(') ++l;
        else              ++r;
        
        if(r > l) return false;
    }
    return true;
}

string convert(const string& input)
{
    if(input.empty()) return "";
    
    int l = 0, r = 0;
    for(int i = 0; i < input.size(); ++i)
    {
        if(input[i] == ')') ++r;
        else                ++l;
        
        if(l == r) break;
    }
    
    string u = input.substr(0, l + r);
    string v = input.substr(u.size(), input.size() - u.size());
    
    if(correct(u))
    {
        u.append(convert(v));
        return u;
    }
    else
    {
        string tmp = "(";
        tmp.append(convert(v));
        tmp.append(")");
        
        u.erase(u.end() - 1);
        u.erase(u.begin());
        for(int i = 0; i < u.size(); ++i)
        {
            if(u[i] == '(') u[i] = ')';
            else            u[i] = '(';
        }
        tmp.append(u);
        return tmp;
    }
}

string solution(string p) {
    return convert(p);
}