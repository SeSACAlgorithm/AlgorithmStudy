#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define ONE_HOUR 3600
#define ONE_MINUTE 60

struct Task
{
    int start;
    int end;
    
    Task() : start(0), end(0) {}
    Task(int s, int e) : start(s), end(e) {}
};

int solution(vector<string> lines) {
    int answer = 0;
    
    int hh, mm, ss;
    int start_time, end_time;
    int work_time;
    vector<Task> times;
    for(const string& s : lines)
    {
        hh = stoi(s.substr(11, 2));
        mm = stoi(s.substr(14, 2));
        ss = stoi(s.substr(17, 2));
        ss += hh * ONE_HOUR + mm * ONE_MINUTE;
        
        end_time = stoi(s.substr(20, 3));
        end_time += ss * 1000;
        
        int int_part = 0, decimal_part = 0;
        for(int i = 24; i < s.size() - 1; ++i)
        {
            if(s[i] == '.')
            {
                int_part = stoi(s.substr(24, i - 24));
                decimal_part = stoi(s.substr(i + 1, s.size() - i - 2));
                break;
            }
        }
        if(int_part == 0)
            int_part = stoi(s.substr(24, s.size() - 25));
        
        work_time = int_part * 1000 + decimal_part;
        
        start_time = end_time - work_time + 1;
        times.emplace_back(Task(start_time, end_time));
    }
    sort(times.begin(), times.end(), [](Task a, Task b) { return a.end < b.end; });
    
    int max = 0, count = 0;
    int limit = 0;
    for(int i = 0; i < times.size(); ++i)
    {
        limit = times[i].end + 999;
        count = 1;
        for(int j = i + 1; j < times.size(); ++j)
        {
            if(times[j].start > limit) continue;
            ++count;
        }
        if(count > max)
            max = count;
    }
    
    return max;
}
