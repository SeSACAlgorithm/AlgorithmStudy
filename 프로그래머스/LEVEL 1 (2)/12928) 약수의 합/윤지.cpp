#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> tmp ;
    
    for(int i = 1; i <= n; i ++){
        if(n % i == 0){
            tmp.push_back(i);
        }
    }
    
    
    for(int i = 0 ; i < tmp.size(); i++){
        answer += tmp[i];
    }
    
    return answer;
}
