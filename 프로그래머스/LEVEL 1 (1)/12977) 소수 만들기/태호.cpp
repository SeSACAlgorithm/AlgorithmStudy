#include <vector>
#include <iostream>
using namespace std;

bool vis[3003];

int solution(vector<int> nums) {
    int answer = 0;

    for (int i = 2; i < 3003; ++i)
    {
        if(vis[i])
            continue;

        for (int j = i + i; j < 3003; j += i)
            vis[j] = true;
    }


    for (int i = 0; i < nums.size(); ++i)
        for (int j = i + 1; j < nums.size(); ++j)
            for (int k = j + 1; k < nums.size(); ++k)
                if (!vis[nums[i] + nums[j] + nums[k]])
                    answer++;


    return answer;
}
