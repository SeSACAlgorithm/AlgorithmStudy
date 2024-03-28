#include <string>
#include <sstream>
#include <vector>
#include <climits>

using namespace std;

string solution(string s) {
    string answer = "";
    
    stringstream ss;
    ss.str(s);
    
    int num = 0;
    int min = INT_MAX, max = INT_MIN;
    while(ss >> num)
    {
        if(num > max) max = num;
        if(num < min) min = num;
    }
    
    return answer + to_string(min) + " " + to_string(max);
}