#include <vector>

using namespace std;

long long solution(int a, int b) {
    if(a == b) return a;
    
    long long high = max(a, b);
    long long low = min(a, b);
    long long big = high * (high + 1) / 2;
    long long small = low * (low - 1) / 2;
    
    return big - small;
}