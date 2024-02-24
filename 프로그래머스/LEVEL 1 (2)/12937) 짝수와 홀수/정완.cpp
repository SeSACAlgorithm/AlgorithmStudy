#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    string ans = "";
    if(num%2==0)
    {
        ans = "Even";
    }
    else
    {
        ans = "Odd";
    }
    return ans;
}