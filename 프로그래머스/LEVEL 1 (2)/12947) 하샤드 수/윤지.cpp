#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    
    string tmp = to_string(x);
    int sum = 0 ;
    
    for(int i = 0 ; i < tmp.size(); i++)
    {
        int tmpX = tmp[i] - '0';
        sum += tmpX;
    }
    
    if(x%sum != 0) answer = false;
    
    return answer;
}
