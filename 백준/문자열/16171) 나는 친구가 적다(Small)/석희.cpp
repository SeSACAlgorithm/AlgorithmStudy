#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string str, S;
    
    getline(cin, str);

    for(auto c : str)
    {
        if(c >= '0' && c <= '9') continue;
        S += c;
    }

    string keyword;
    getline(cin, keyword);

    if(S.find(keyword) != string::npos) cout << "1";
    else cout << "0";
}