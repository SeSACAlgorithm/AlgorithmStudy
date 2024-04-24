#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer = { 0, 0 };

    while (true)
    {
        auto iter = find(s.begin(), s.end(), '0');
       
        if (iter == s.end())
        {
            ++answer[0];

            if (s.size() == 1)
                break;
            else
            {
                int temp = s.size();
                s.clear();

                while (temp)
                {
                    int bit = temp & 1;
                    s = (bit == 0 ? '0' : '1') + s;
                    temp >>= 1;
                }

            }
        }
        else
        {
            s.erase(iter);
            ++answer[1];
        }
    }

    return answer;
}
