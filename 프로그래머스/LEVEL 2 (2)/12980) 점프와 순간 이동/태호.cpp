#include <iostream> using namespace std; int solution(int n) { int answer = 0; while (n){ if(n % 2 == 1){ ++answer; n = (n - 1) / 2;} else n = n / 2;}return answer; }
