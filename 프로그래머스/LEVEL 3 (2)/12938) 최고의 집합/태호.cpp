#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    if(n > s)
        return { -1 };

    while(n != 1)
    {
        int k = s / n; 
        answer.push_back(k);
        s -= k;
        --n;
    }

    answer.push_back(s);

    return answer;
}
