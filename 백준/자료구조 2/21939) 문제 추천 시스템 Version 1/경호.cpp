#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    map<int, set<int>> problems;
    map<int, int> numbers;
    int number, level;
    for(int i = 0; i < N; ++i)
    {
        cin >> number >> level;
        problems[level].insert(number);
        numbers.emplace(number, level);
    }

    int M;
    cin >> M;

    vector<string> type{"add", "recommend", "solved"};
    vector<int> answer;
    string order;
    for (int i = 0; i < M; ++i)
    {
        cin >> order;
        if(order == type[0])
        {
            cin >> number >> level;
            problems[level].insert(number);
            numbers.emplace(number, level);
        }
        else if(order == type[1])
        {
            cin >> number;
            auto level_it = number == 1 ? --problems.end() : problems.begin();
            auto number_it = number == 1 ? --level_it->second.end() : level_it->second.begin();
            answer.emplace_back(*number_it);
        }
        else if (order == type[2])
        {
            cin >> number;
            set<int>& target_set = problems[numbers[number]];
            target_set.erase(number);
            if (target_set.empty())
                problems.erase(numbers[number]);
        }
    }

    for (const int& ans : answer)
        cout << ans << "\n";
}