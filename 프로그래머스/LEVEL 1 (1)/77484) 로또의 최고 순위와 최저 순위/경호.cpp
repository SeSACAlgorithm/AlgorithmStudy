#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    map<int, int> nums;
    for(int i = 0; i < lottos.size(); i++)
        nums[lottos[i]]++;
    
    vector<int> answer(2);
    int count = 0;
    for(int n : win_nums)
        count += nums[n];
    
    int bigger = abs(count + nums[0] - 6) + 1;
    int smaller = abs(count - 6) + 1;
    answer[0] = bigger < 6 ? bigger : 6;
    answer[1] = smaller < 6 ? smaller : 6;
    return answer;
}