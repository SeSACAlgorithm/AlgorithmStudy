#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[1001];
vector<string> answer;

bool dfs(string cur, const vector<vector<string>>& tickets)
{
    if (answer.size() == tickets.size() + 1)
        return true;

    for (int i = 0; i < tickets.size(); ++i)
    {
        if (visited[i]) continue;

        if (tickets[i][0] == cur)
        {
            visited[i] = true;
            answer.push_back(tickets[i][1]);

            if (dfs(tickets[i][1], tickets))
                return true;

            answer.pop_back();
            visited[i] = false;
        }
    }

    return false;
}

vector<string> solution(vector<vector<string>> tickets) {

    sort(tickets.begin(), tickets.end(), []
        (const vector<string>& a, const vector<string>& b)
        {
            return a[1] < b[1];
        }
    );

    answer.push_back("ICN");
    dfs("ICN", tickets);

    return answer;
}
