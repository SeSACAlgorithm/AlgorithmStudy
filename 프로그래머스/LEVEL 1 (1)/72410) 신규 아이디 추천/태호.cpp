#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string answer = "";

    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);

    string str = "";
    int index = 0;

    vector<char> vec;
    vec.push_back('-');
    vec.push_back('_');
    vec.push_back('.');

    for(int i = 0; i < 10; ++i)
        vec.push_back(i + '0');

    for (int i = 0; i < 26; ++i)
        vec.push_back(i + 'a');

    for (int i = 0; i < new_id.size(); ++i)
    {
        for (int j = 0; j < vec.size(); ++j)
        {
            if (vec[j] == new_id[i])
            {
                str += new_id[i];
                break;
            }
        }
    }

    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == '.')
        {
            int lastindex = 0;

            for (int j = i + 1; j < str.size(); ++j)
            {
                if(str[j] != '.')
                    break;

                ++lastindex;

            }

            if (lastindex)
            {
                str.erase(str.begin() + i, str.begin() + i + lastindex);
            }
        }
    }


    if (str.size() > 0)
    {
        auto iter = str.begin();

        if(*iter == '.')
            str.erase(iter);
    }

    if (str.size() > 0)
    {
        auto iter = str.end() - 1;

        if (*iter == '.')
            str.erase(iter);
    }

    if(str.empty())
        str = "a";

    if (str.size() >= 16)
    {
        str = str.substr(0, 15);

        auto iter = str.end() - 1;

        if (*iter == '.')
            str.erase(iter);
    }

    if (str.size() < 3)
    {
        while (str.size() != 3)
        {
            str += str[str.size() - 1];
        }
    }

    return str;
}
