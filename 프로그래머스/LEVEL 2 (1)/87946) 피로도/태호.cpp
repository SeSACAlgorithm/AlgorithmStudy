#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    vector<int> temp(dungeons.size());

    for(int i = 0; i < temp.size(); ++i)
        temp[i] = i;

    do
    {
        int n = k;
        int num = 0;

        for (int i = 0; i < dungeons.size(); ++i)
        {
            if(n < dungeons[temp[i]][0])
                break;

            n -= dungeons[temp[i]][1];

            if (n < 0)
                break;

            ++num;
        }
            
        answer = max(answer, num);

    } while (next_permutation(temp.begin(), temp.end()));

    return answer;
}
