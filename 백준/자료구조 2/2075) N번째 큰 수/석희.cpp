// 문제 분석
/*
    만약 pq의 크기가 N보다 크면 작은수부터 없애주기
    -> 이러면 결국 pq에는 제일 큰수 ~ N번째 숫자만 남아있음

    * 주의할 점 * 
    1. 입력값이 크기 때문에 아래것들 추가해야 함!
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

*/

#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq_num;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    cin >> N;

    for(int i = 0; i < N * N; i++)
    {
        cin >> num;
        pq_num.push(num);

        if(pq_num.size() > N) pq_num.pop();
    }

    cout << pq_num.top();
}