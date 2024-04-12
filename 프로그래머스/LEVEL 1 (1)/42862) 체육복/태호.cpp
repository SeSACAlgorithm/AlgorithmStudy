#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool lostCloth[32];
bool reserveCloth[32];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for (int i = 0; i < lost.size(); ++i)
        lostCloth[lost[i]] = true;

    for (int i = 0; i < reserve.size(); ++i)
    {
        if(!lostCloth[reserve[i]])
            reserveCloth[reserve[i]] = true;
        else
            lostCloth[reserve[i]] = false;
    }
        

    for (int i = 0; i < lost.size(); ++i)
    {
        if (reserveCloth[lost[i] - 1])
        {
            reserveCloth[lost[i] - 1] = false;
            lostCloth[lost[i]] = false;
        }
        else if (reserveCloth[lost[i] + 1])
        {
            reserveCloth[lost[i] + 1] = false;
            lostCloth[lost[i]] = false;
        }
    }

    for (int i = 0; i < lost.size(); ++i)
        if (lostCloth[lost[i]])
            --answer;


    return answer;
}
