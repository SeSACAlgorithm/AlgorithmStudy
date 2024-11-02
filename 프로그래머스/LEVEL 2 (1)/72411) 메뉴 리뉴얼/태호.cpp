#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 2가지 이상 단품메뉴 구성
// 2명 이상 -> 단품메뉴 == 메뉴 후보에 포함함
// 완전 탐색 느낌?
// for문 돌려서 한개씩 해쉬로 묶어보자
// unordered_map<string, int> 로 조합 몇갠지 확인해보자.
// n, m이 둘다 작음 ㅇㅇ 백트래킹해야할듯? (조합으로다가)

bool visited[30];

// 코스 요리 추가하는 변수
unordered_map<string, int> freq_course;
// 답 비교하는 변수 나중에 vector에 넣어주자.
unordered_map<int, vector<pair<string, int>>> freq_count;

void func(const string& s, string cur, int k)
{
    // 오름차순(비교할때도 필수)
    sort(cur.begin(), cur.end());

    int x = ++freq_course[cur];
    int n = cur.size();    


    if(freq_count[n].empty())
    {
        if(x > 1)
            freq_count[n].push_back({cur, x});
    }
    else
    {
        int num = freq_count[n][0].second;

        if(num < freq_course[cur])
        {
            freq_count[n].clear();
            freq_count[n].push_back({cur, x});
        }
        else if(num == freq_course[cur])
            freq_count[n].push_back({cur, x});
    }


    for(int i = k; i < s.size(); ++i)
    {
        if(!visited[i])
        {
            visited[i] = true;
            func(s, cur + s[i], i + 1);
            visited[i] = false;
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;


    // 백트래킹
    for(int i = 0; i < orders.size(); ++i)
        func(orders[i], "", 0);

    for(int i = 0; i < course.size(); ++i)
    {
        vector<pair<string, int>>& v = freq_count[course[i]];   
        sort(v.begin(), v.end());

        for(int i = 0; i < v.size(); ++i)
            answer.push_back(v[i].first);

    }

    sort(answer.begin(), answer.end());

    return answer;
}
