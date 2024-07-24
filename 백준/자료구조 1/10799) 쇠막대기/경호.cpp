#include <iostream>
#include <vector>
#include <string>

using namespace std;

void add_count(vector<int>& counts)
{
    for (int i = 0; i < counts.size(); ++i)
        ++counts[i];
}

int main()
{
    string data;
    cin >> data;

    int answer = 0;
    vector<int> counts;

    int limit = data.size() - 1;
    for(int i = 0; i < limit; ++i)
    {
	    if(data[i] == '(')
	    {
            // 레이저인 경우
		    if(data[i + 1] == ')')
		    {
                add_count(counts);
                ++i;
		    }
            // 막대기 추가
            else
            {
                counts.emplace_back(0);
            }
	    }
        else
        {
            answer += counts.back() + 1;
            counts.erase(counts.end() - 1);
        }
    }

    if(false == counts.empty())
        answer += counts[0] + 1;
    cout << answer;
}