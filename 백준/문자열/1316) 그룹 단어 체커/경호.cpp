#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<string> words(N);
    for (int i = 0; i < N; ++i)
        cin >> words[i];

    int answer = 0;
    for(const string& s : words)
    {
        map<char, int> idx;
        bool is_group_word = true;
	    for(int i = 0; i < s.size(); ++i)
	    {
            // 나온 적이 없거나 바로 전에 나온 문자라면 인덱스 갱신
            // 그 외의 경우, 그룹 문자가 아니므로 break
            if (idx[s[i]] == 0 || idx[s[i]] == i)
                idx[s[i]] = i + 1;
            else
            {
                is_group_word = false;
                break;
            }
	    }
        if (is_group_word)
            ++answer;
    }

    cout << answer;
}