#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> vec1(N);
    vector<int> vec2(M);
    for (int i = 0; i < N; ++i)
        cin >> vec1[i];
    for (int i = 0; i < M; ++i)
        cin >> vec2[i];

    int idx1 = 0, idx2 = 0;
	int limit = N + M;
    vector<int> answer(N + M);
    while(idx1 + idx2 < limit)
    {
        // 한 쪽이 끝에 도달한 경우
	    if(idx1 == N)
	    {
            answer[idx1 + idx2] = vec2[idx2]; 
            ++idx2;
            continue;
	    }
        if(idx2 == M)
        {
            answer[idx1 + idx2] = vec1[idx1];
            ++idx1;
            continue;
        }

        // 양 쪽 다 남아있는 경우
        if(vec1[idx1] < vec2[idx2])
        {
            answer[idx1 + idx2] = vec1[idx1];
            ++idx1;
        }
        else
        {
            answer[idx1 + idx2] = vec2[idx2];
            ++idx2;
        }
    }

    for (const int& ans : answer)
        cout << ans << " ";
}