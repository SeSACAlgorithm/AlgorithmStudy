#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
    bool passing = false;

    int high = 200000000, low = 0;
    int cur = (high + low) / 2;
    while(low < high)
    {
        int len = 1;
        bool can_pass = true;
        for(int i = 0; i < stones.size(); ++i)
        {
            if (stones[i] >= cur)
            {
                len = 1;
                continue;
            }

            if(0 == len) passing = true;
            ++len;
            if (len > k)
            {
                can_pass = false;
                break;
            }
        }
        if (len > k) can_pass = false;
        
        if(can_pass)
            low = cur + 1;
        else
            high = cur;
        cur = (high + low) / 2;
    }

    return cur - 1;
}