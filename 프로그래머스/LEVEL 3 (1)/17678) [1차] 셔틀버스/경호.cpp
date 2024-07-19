#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define ONE_HOUR 60

string solution(int n, int t, int m, vector<string> timetable) {
    queue<int> crews;
    sort(timetable.begin(), timetable.end());
    
    int hh = 0, mm = 0;
    for(const string& s : timetable)
    {
        hh = stoi(s.substr(0, 2));
        mm = stoi(s.substr(3, 2));
        crews.push(hh * ONE_HOUR + mm);
    } 
    
    int start = 9 * ONE_HOUR;
    int end = 24 * ONE_HOUR;
    int cur = start;
    int last = 0;
    while(n > 0)
    {
        int count = 0;
        --n;
        // 줄 선 인원 체크
        while(false == crews.empty() && count < m)
        {
            if(crews.front() > cur) break;
            
            last = crews.front();
            crews.pop();
            ++count;
        }
        // 마지막 버스인데 인원이 가득 찬 경우
        if(n == 0 && count == m)
        {
            cur = last - 1; 
            break;
        }
        
        if(n > 0) cur += t;
    }
    
    hh = cur / 60;
    mm = cur % 60;
    string hour = hh > 9 ? to_string(hh) : "0" + to_string(hh);
    string minute = mm > 9 ? to_string(mm) : "0" + to_string(mm);
    return hour + ":" + minute;
}