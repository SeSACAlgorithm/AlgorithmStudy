#include <string>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool check_command(char c)
{
    if(c >= '0' && c <= '9')
        return true;
    
    if(c >= 'a' && c <='z')
        return true;
    
    if(c == '-' || c == '_' || c == '.')
        return true;
    
    return false;
}
string solution(string new_id) {
    string ans = "";
    string tmp = "";
    
    // step 1
    for(char c : new_id)  
        ans += tolower(c);  // 대소문자
    
    // step 2
    for(char c : ans)    // 소문자, 숫자, 특문
        if(check_command(c))
            tmp += c;
    
    ans = tmp;
    tmp = "";
    
    // step 3
    for(int i=0; i<ans.size(); i++)
    {
        if(ans[i] == '.' && ans[i+1] == '.')
            continue;

        tmp += ans[i];
    }
    ans = tmp;

    // step 4
    if(ans[0] == '.')
        ans.erase(ans.begin());

    if(ans[ans.size() - 1] == '.')
        ans.erase(ans.end() - 1);

    // step 5
    if(ans.size() == 0)
        ans = "a";

    // step 6
    if(ans.size() >=16)
        ans.erase(ans.begin() + 15, ans.end());
    if(ans[ans.size() - 1] == '.')
        ans.erase(ans.end() - 1);

    // step 7
    if(ans.size() <=2)
    {
        char new_id_end = ans[ans.size() - 1];
        while(ans.size() < 3)
            ans += new_id_end;
    }
    
    return ans;
}
