#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool> v(n + 1, true);
    
    for(int i=2; i*i<=n; i++){
        if(v[i]){
            for(int j=i*i; j<=n; j+=i){
                v[j] = false;
            }
        }
    }
    
    for(int i=2; i<v.size(); i++){
        if(v[i]) answer++;
    }
    return answer;
}