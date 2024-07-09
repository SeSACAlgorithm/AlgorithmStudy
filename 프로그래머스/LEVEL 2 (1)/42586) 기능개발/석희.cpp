// 주의할 것
/*
    항상 배포되지 않은 항목을 기준으로 비교해야 함!
*/


#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    vector<int> v_temp;

    for (int i = 0; i < progresses.size(); i++)
    {
        v_temp.push_back(ceil((float)(100 - progresses[i]) / (float)speeds[i]));
    }

    int progress_size = 1;                   // 각 배포마다 몇 개의 기능이 배포되는지
    int no_release_progress = v_temp[0];     // 아직 배포하지 않은 항목
    for (int i = 1; i < v_temp.size(); i++)
    {
        if (no_release_progress >= v_temp[i])
        {
            progress_size++;
        }
        else
        {
            answer.push_back(progress_size);
            no_release_progress = v_temp[i];
            progress_size = 1;
        }
    }

    answer.push_back(progress_size);
    return answer;
}