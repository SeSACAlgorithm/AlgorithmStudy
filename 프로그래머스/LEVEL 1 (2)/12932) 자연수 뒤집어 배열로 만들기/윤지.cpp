#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    vector<char> str_ans;
    
    string tmp = to_string(n);
    
    for(int i = tmp.size()-1 ; i >= 0; i--){
        str_ans.push_back(tmp[i]);
       
    }
    
    for(int i = 0 ; i < str_ans.size(); i++){
        int a = str_ans[i] - '0';
        answer.push_back(a);
    }
    
    
    return answer;
}
