#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;

    vector<vector<string>> words;
    for(int i = 0; i < tc; ++i)
    {
        int count;
        cin >> count;

        words.emplace_back(vector<string>(count));
        for (int j = 0; j < count; ++j)
            cin >> words[i][j];
    }

    vector<string> answer(tc);
    string temp = "";
    string reverse = "";
    for(int i = 0; i < words.size(); ++i)
    {
        bool check = true;
	    for(int j = 0; j < words[i].size(); ++j)
	    {
		    for(int k = 0; k < words[i].size(); ++k)
		    {
                if (j == k) continue;

                temp = words[i][j] + words[i][k];
                reverse = string(temp.rbegin(), temp.rend());

                if(temp == reverse)
                {
                    answer.emplace_back(temp);
                    check = false;
                    break;
                }
		    }
            if (false == check)
                break;
	    }
        if(check)
			answer.emplace_back("0");
    }

    for (string s : answer)
        cout << s << endl;
}