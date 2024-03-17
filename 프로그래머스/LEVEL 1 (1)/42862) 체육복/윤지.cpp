#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    vector<int> tmp(n, 1);

    for (auto i : lost)      tmp[i - 1]--;
    for (auto i : reserve)   tmp[i - 1]++;

    for (int k = 0; k < n; k++) {
        if (tmp[k] == 0) {
            if (tmp[k - 1] == 2)
            {
                tmp[k] += 1;
                tmp[k - 1] -= 1;
            }
            else if (tmp[k + 1] == 2)
            {
                tmp[k] += 1;
                tmp[k + 1] -= 1;
            }
        }
    }

    for (int a = 0; a < tmp.size(); a++) {
        if (tmp[a] >= 1) answer++;
    }


    return answer;
}