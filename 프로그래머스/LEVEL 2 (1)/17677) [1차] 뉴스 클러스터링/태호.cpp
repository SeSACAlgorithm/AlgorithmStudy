#include <string>
#include <set>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    multiset<string> S1;
    multiset<string> S2;

    if(islower(str1[0])) str1[0] = toupper(str1[0]);
    if (islower(str2[0])) str2[0] = toupper(str2[0]);

    for (int i = 0; i < str1.size() - 1; ++i)
    {
        string str = "";
        if (islower(str1[i + 1]))
            str1[i + 1] = toupper(str1[i + 1]);
        
        if(!isupper(str1[i]) || !isupper(str1[i + 1]))
            continue;

        str += str1[i]; str += str1[i + 1];
        S1.emplace(str);
    }

    for (int i = 0; i < str2.size() - 1; ++i)
    {
        string str = "";
        if (islower(str2[i + 1]))
            str2[i + 1] = toupper(str2[i + 1]);
          
        if (!isupper(str2[i]) || !isupper(str2[i + 1]))
            continue;

        str += str2[i]; str += str2[i + 1];
        S2.emplace(str);
    }
    

    int x = 0, y =0;
    auto iter = S1.begin();

    while( iter != S1.end())
    {
        if(S2.empty())
            break;

        auto S2iter = S2.find(*iter);

        if (S2iter != S2.end())
        {
            S2.erase(S2iter);
            iter = S1.erase(iter);
            ++y;
            ++x;
        }
        else
            ++iter;
    }

    
    y += S2.size() + S1.size();

    if (x == 0 && y == 0)
        return 65536;

    if (x == 0 && y > 0)
        return 0;

    return float(65536.f) * (float(x) / y);
}
