#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    auto last = unique(arr.begin(), arr.end());

    for (auto it = arr.begin(); it != last; ++it) {
        answer.push_back(*it);
    }

    return answer;
}
