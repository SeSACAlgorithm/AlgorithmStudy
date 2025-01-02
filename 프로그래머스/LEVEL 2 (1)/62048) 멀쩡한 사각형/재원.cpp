#include <iostream>
#include <algorithm> // std::gcd를 사용하기 위해 필요
using namespace std;

long long solution(int w, int h) {
    // W와 H의 최대공약수를 구함
    long long gcd = __gcd(w, h);
    
    // 전체 사각형 수에서 대각선이 지나가는 사각형을 뺌
    long long totalSquares = static_cast<long long>(w) * h;
    long long invalidSquares = w + h - gcd;
    long long answer = totalSquares - invalidSquares;

    return answer;
}
