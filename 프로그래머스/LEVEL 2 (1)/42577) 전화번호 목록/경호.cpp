#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    
    string bef = "", fwd = "";
    for(int i = 1; i < phone_book.size(); i++)
    {
        bef = phone_book[i - 1];
        fwd = phone_book[i];
        
        if(bef == fwd.substr(0, bef.size()))
            return false;
    }
    return true;
}