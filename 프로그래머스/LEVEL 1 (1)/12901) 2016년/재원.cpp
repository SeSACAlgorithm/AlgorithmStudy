#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    int daysInMonth[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string daysOfWeek[] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    
    int totalDays = 0;
    for (int i = 1; i < a; ++i) {
        totalDays += daysInMonth[i];
    }
    totalDays += b - 1; // b 일은 해당 월의 날짜를 나타냄. 따라서 -1 을 해줘야 함
    
    // 2016년 1월 1일이 금요일이므로, 0일을 기준으로 요일을 계산
    int dayOfWeekIndex = totalDays % 7;
    
    return daysOfWeek[dayOfWeekIndex];
}
