#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    if(num == 1)
        return 0;
    
    long n = num;
    for(int i = 1; i <= 500; i++)
    {
        n = (n & 1) == 0 ? n / 2 : n * 3 + 1;
        if(n == 1)
            return i;
    }
    
    return -1;
}