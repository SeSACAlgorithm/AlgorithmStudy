#include <string>
#include <vector>
#include <math.h>

using namespace std;

string solution(int n) {
    string answer = "";
    vector<string> otf{ "1", "2", "4" };
    
    vector<int> pow3(17);
    for(int i = 1; i <= 17; i++)
        pow3[i - 1] = pow(3, i);
    
    int layer = 0;
    while(n > 0)
    {
        if(n <= pow3[layer])
            break;
        
        n -= pow3[layer];
        ++layer;
    }
    
    --n;
    int div = 0;
    while(layer > 0)
    {
        div = n / pow3[layer - 1];
        answer += otf[div];
        
        n %= pow3[layer - 1];
        --layer;
    }
    answer += otf[n];
    return answer;
}


