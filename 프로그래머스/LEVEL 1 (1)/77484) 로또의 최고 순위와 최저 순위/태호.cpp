#include <string>
#include <vector>
#include <set>

using namespace std;

int lot[7] = { 6, 6, 5, 4, 3, 2, 1};

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int m = 0;
    int zeronum = 0;

    multiset<int> nums;

    for (int i = 0; i < win_nums.size(); ++i)
        nums.insert(win_nums[i]);

    for (int i = 0; i < lottos.size(); ++i)
    {
        if (lottos[i] == 0)
        {
            ++zeronum;
            continue;
        }

        if (nums.end() != nums.find(lottos[i]))
        {
            ++m;
        }
    }

    answer.push_back(lot[m + zeronum]);
    answer.push_back(lot[m]);

    return answer;
}
