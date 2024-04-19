#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> s) {
    int answer = 0;
    deque<string> dq;

    if(0 == cacheSize)
        return s.size() * 5;

    for(int i = 0; i < s.size(); ++i)
        transform(s[i].begin(), s[i].end(), s[i].begin(), ::tolower);

    for (int i = 0; i < s.size(); ++i)
    {
        auto iter = find(dq.begin(), dq.end(), s[i]);

        if (iter != dq.end())
        {
            dq.erase(iter);
            ++answer; 
        }
        else
        {
            if (dq.size() == cacheSize)
                dq.pop_front();

            answer += 5;
        }

        dq.push_back(s[i]);
    }

    return answer;
}
