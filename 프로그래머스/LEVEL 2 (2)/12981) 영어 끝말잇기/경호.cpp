#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    map<string, bool> check;
    
    int limit = words.size() / n;
    char last = words[0][0];
    int idx = 0;
    for(int count = 0; count < limit; ++count)
    {
        for(int i = 0; i < n; ++i)
        {
            idx = count * n + i;
            if(words[idx][0] != last || check[words[idx]])
                return vector<int>{i + 1, count + 1};
            
            check[words[idx]] = true;
            last = words[idx].back();
        }
    }

    return vector<int>{0, 0};
}