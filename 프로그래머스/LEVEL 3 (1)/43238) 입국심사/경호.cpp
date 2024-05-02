#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long low = 0;
    long long high = 10000000000000000;
    long long middle = (high + low) / 2;
    while(low < high)
    {
        long long count = 0;
        for(int t : times)
            count += middle / t;
        
        if(count >= n)
            high = middle;
        else
            low = middle + 1;
        
        middle = (high + low) / 2;
    }
    
    return middle;
}