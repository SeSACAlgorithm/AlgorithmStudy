#include <string>
#include <vector>
#include <sstream>
#include <algorithm>


using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> vec;

    int Max = -1;
    int Min = 1000001;
    
    for (int i = 0; i < operations.size(); ++i)
    {
        stringstream ss;
        ss.str(operations[i]);
        
        while (!ss.eof())
        {
            string s;
            ss >> s;

            if ('I' == s[0])
            {
                ss >> s;
                int k = stoi(s);
                vec.push_back(k);
            }
            if ('D' == s[0])
            {
                ss >> s;

                if(vec.empty())
                    continue;

                if ('1' == s[0])
                    vec.erase(find(vec.begin(), vec.end(), *max_element(vec.begin(), vec.end())));

                else if ('-' == s[0])
                    vec.erase(find(vec.begin(), vec.end(), *min_element(vec.begin(), vec.end())));    
            }

        }
    }

    if(vec.empty())
        return vector<int>{0,0};

    return vector<int>({*max_element(vec.begin(), vec.end()), *min_element(vec.begin(), vec.end()) });
}
