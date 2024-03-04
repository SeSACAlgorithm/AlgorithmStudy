#include <math.h>

using namespace std;

long long solution(long long n) {
    long long square = sqrt(n);
    return pow(square, 2) == n ? pow(square + 1, 2) : -1;
}