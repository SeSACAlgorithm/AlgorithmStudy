#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> VS;
vector<char> VC;

long long solution(string expression) {
    long long answer = 0;

    string s;
    
    for(int i = 0; i < expression.size(); ++i)
    {
        if (expression[i] == '-' || expression[i] == '*' || expression[i] == '+')
        {
            VS.push_back(s);
            s = expression[i];
            VS.push_back(s);
            s = "";

            bool bSame = false;

            for (int j = 0; j < VC.size(); ++j)
            {
                if (expression[i] == VC[j])
                {
                    bSame = true;
                    break;
                }
            }

            if(!bSame)
                VC.push_back(expression[i]);
                
        }
        else
            s += expression[i];
    }

    if(!s.empty())
        VS.push_back(s);


    vector<int> vec(VC.size());
    for(int i = 0; i < vec.size(); ++i)
        vec[i] = i + 1;

    do
    {
        long long k = 0;
        vector<string> tempVS = VS;


        for (int i = 0; i < vec.size(); ++i)
        {
            string str; str += VC[vec[i] - 1];

            while (true)
            {
                auto iter = find(tempVS.begin(), tempVS.end(), str);
                if (iter == tempVS.end()) break;

                int dist = distance(tempVS.begin(), iter);

                long long ans = 0;
                

                if (*iter == "-")   
                    ans = stoll(tempVS[dist - 1]) - stoll(tempVS[dist + 1]);

                if (*iter == "+")
                    ans = stoll(tempVS[dist - 1]) + stoll(tempVS[dist + 1]);

                if (*iter == "*")
                    ans = stoll(tempVS[dist - 1]) * stoll(tempVS[dist + 1]);


                --iter;
                for (int i = 0; i < 3; ++i)
                    iter = tempVS.erase(iter);

                tempVS.insert(iter, to_string(ans));
                k = ans;
            }
            
        }

        answer = max(abs(k), answer);

    } while (next_permutation(vec.begin(), vec.end()));
    

    return answer;
}
