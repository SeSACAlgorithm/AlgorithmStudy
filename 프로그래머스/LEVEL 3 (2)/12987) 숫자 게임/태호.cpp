#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    sort(A.begin(), A.end()); // 1, 3, 5, 7
    sort(B.begin(), B.end()); // 1, 3, 5, 7

    int aidx = 0;
    
    for (int i = 0; i < B.size(); ++i)
    {
        int mn = 1000000002;
        int bidx = -1;

        int k = B[i] - A[aidx];
        if(k > 0)
        {
            mn = k;
            bidx = i;
        }

        if(bidx != -1)
        {
            ++aidx;
            ++answer;
        }
    }

    return answer;
}
