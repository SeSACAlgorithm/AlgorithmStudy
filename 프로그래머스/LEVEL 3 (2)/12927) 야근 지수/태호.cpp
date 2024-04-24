#include <string>
#include <vector>
#include <set>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    multiset<int> S(works.begin(), works.end());

    while (n--)
    {
       if(S.empty())
          return 0;

       int k = *--S.end() - 1;
       S.erase(--S.end());

       if(k != 0)
         S.emplace(k);
    }
     
    for (auto elem : S)
        answer += elem * elem;


    return answer;
}
