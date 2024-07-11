#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    map<string, int> nums;
    map<int, string> names;

    string temp;
    for(int i = 0; i < N; ++i)
    {
        cin >> temp;
        nums.insert({temp, i + 1});
        names.insert({i + 1, temp});
    }

    vector<string> answers(M);
    for(int i = 0; i < M; ++i)
    {
        cin >> temp;
    	answers[i] = isdigit(temp[0]) ? names[stoi(temp)] : to_string(nums[temp]);
    }

    for (const string& s : answers)
        cout << s << '\n';
}