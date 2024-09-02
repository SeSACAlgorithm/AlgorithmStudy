#include <iostream>
#include <vector>

using namespace std;

bool check_count(const vector<int>& times, const long long target, int M)
{
    // 목표 시간동안 각 검사대에서 검사할 수 있는 인원수를 count에 누적
    // count가 목표 인원 수(M) 이상이라면 true, 아니라면 false 반환
    long long count = 0;
    for (int t : times)
    {
        count += target / t;
        if (count >= M) 
            break;
    }

    return count >= M;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    // N개의 검사대별 검사 시간 저장
    vector<int> times(N);
    for (int i = 0; i < N; ++i)
        cin >> times[i];

    // 최소값과 최대값 설정
    // 최대값 = 최대 검사 시간 * 검사 인원 수
    long long max_time = 1000000000;
    long long high = max_time * M;
    long long low = 0;
    // 최대값이 더 큰 동안 검사 반복
    // (타겟 시간 / 각 검사대별 검사 시간) 을 모두 더하여 몇명 검사할 수 있는지 체크
    // 결과가 M 이상이라면 시간을 좀 더 줄일 수 있으므로 high값을 갱신
    // 결과가 M 미만이라면 시간을 좀 더 늘려야 하므로 low값을 갱신
    while(high > low)
    {
        long long target = (high + low) / 2;
        if (check_count(times, target, M))
            high = target;
        else
            low = target + 1;
    }
    // 조건을 만족한 경우 high로 갱신하므로 high 출력
    cout << high;
}