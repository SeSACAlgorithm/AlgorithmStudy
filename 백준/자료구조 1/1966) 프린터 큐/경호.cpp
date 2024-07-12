#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int repeat;
    cin >> repeat;
    vector<int> answer(repeat);

    int N, target;
    for(int i = 0; i < repeat; ++i)
    {
        cin >> N >> target;
        queue<int> que;
        vector<int> nums(N);

        int temp;
        for (int j = 0; j < N; ++j)
        {
            cin >> temp;
            que.push(temp);
            nums[j] = temp;
        }
        sort(nums.begin(), nums.end());

        int count = 0;
        while(false == que.empty())
        {
            int front = que.front();
	        if(front < nums.back())
	        {
                que.pop();
                que.push(front);
                target = target == 0 ? que.size() - 1 : target - 1;
	        }
            else
            {
                que.pop();
                ++count;
                nums.erase(nums.end() - 1);

                if (target == 0) break;
                --target;
            }
        }

        answer[i] = count;
    }

    for(int num : answer)
        cout << num << endl;
}