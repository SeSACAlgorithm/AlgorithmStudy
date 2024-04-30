#include <vector>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer(n);
    vector<int> vec;

    for (int i = 0; i < answer.size(); ++i)
        answer[i] = i + 1;

    long long mx = 2;

    for (int i = 3; i < n; ++i)
        mx *= i;
  
    --k;
    
    while (n != 1)
    {
        long long div = k / mx;
        long long remain = k % mx;

        vec.push_back(answer[div]);
        k = remain;
        answer.erase(answer.begin() + div);

        mx /= --n;
    }

    for(int i = 0; i < answer.size(); ++i)
        vec.push_back(answer[i]);

    return vec;
}
