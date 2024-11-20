#include<iostream>
#include<queue>

using namespace std;

int main()
{
    // 알파벳에 대응하는 숫자 값
    int alpha[26] = { 3,2,1,2,3,3,3,3,1,1,3,1,3,3,1,2,2,2,1,2,1,1,2,2,2,1 };
    
    queue<int> firstq;
    queue<int> secondq;
    int temp;
    string s;
    cin >> s;

    // 문자열을 숫자로 변환하여 firstq에 저장
    for (int i = 0; i < s.size(); i++) {
        firstq.push(alpha[s[i] - 65]);
    }

    // 큐에서 숫자들을 합쳐 나감
    while (firstq.size() > 1) {
        // 두 개의 값을 합쳐 secondq에 넣음
        secondq = queue<int>();  // secondq를 비우고 시작
        while (!firstq.empty()) {
            if (firstq.size() > 1) {
                temp = firstq.front();
                firstq.pop();
                secondq.push(temp + firstq.front());
                firstq.pop();
            } else {
                secondq.push(firstq.front()); // 하나만 남았으면 그 값을 그대로 넣기
                firstq.pop();
            }
        }
        // secondq를 firstq로 교환
        swap(firstq, secondq);
    }

    // 결과 출력: 짝수면 "You're the winner?", 홀수면 "I'm a winner!"
    if (firstq.front() % 2 == 0) {
        cout << "You're the winner?";
    } else {
        cout << "I'm a winner!";
    }

    return 0;
}

