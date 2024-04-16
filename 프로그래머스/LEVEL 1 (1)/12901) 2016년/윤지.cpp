#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<string> days = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    int day = 0;
    
    for(int i = 1; i < a; i++){
        if(a == 1) break;
        
        if(i == 2) {
            day += 29;
        } else if(i == 4 || i == 6 || i == 9 || i == 11){
            day += 30;
        } else {
            day += 31;
        }
    }
    
    day += b;
    int tmp = (day-1) % 7;
    
    answer = days[tmp];
    
    
    return answer;
}
