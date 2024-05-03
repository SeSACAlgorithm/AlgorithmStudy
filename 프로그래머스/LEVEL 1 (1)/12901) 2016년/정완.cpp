#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string ans = "";
    string day[7] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
    int month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sum = 0;
    
    for(int i=0; i<a-1; i++)
        sum += month[i];
    
    sum += b;
    
    ans = day[sum%7];
    
    return ans;
}
