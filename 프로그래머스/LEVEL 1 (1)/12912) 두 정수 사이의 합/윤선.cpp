#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
   
    long long high = max(a, b);
    long long low = min (a,b);
    long long B = high * (high +1) /2;
    long long A = low * (low - 1) /2;
    
    return B - A;
}
