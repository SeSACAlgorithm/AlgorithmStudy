// 문제 분석
/*
    음식의 스코빌 지수를 담은 배열 scoville
    원하는 스코빌 지수 K

    * 필요한 값 -> 가장 맵지 않은 음식의 스코빌 지수 & 두번째로 맵지 않은 음식의 스코빌 지수
    
    * 종료 조건
      - 모든 값이 K 이상인가? (제일 작은 값이 K 이상이면 모두 작은 것)
      또는 
      - 모든 음식의 스코빌 지수를 더해도 K이상이 안되는가?(-1 반환)

    * 주의할 것
      - 처음부터 모든 값이 K 이상인 경우
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq_food;

    for(int i = 0; i < scoville.size(); i++)
    {
        pq_food.push(scoville[i]);
    }

    if(pq_food.top() >= K) return 0;

    while(pq_food.size() > 1)
    {
        answer++;

        int first = pq_food.top();              // 가장 맵지 않은 음식의 스코빌 지수
        pq_food.pop();
        int second = pq_food.top();             // 두번째로 맵지 않은 음식의 스코빌 지수
        pq_food.pop();
        
        int mix = first + (second * 2);         // 섞은 음식의 스코빌 지수
        pq_food.push(mix);

        if(pq_food.top() >= K) return answer;   // 제일 작은 값이 K 이상이면 모두 작다는 것
    }

    return -1;
}
