#include <string>
#include <vector>
#include <iostream>

using namespace std;

void dfs(int cnt, vector<int> &visited, vector<string>o, string &s, vector<string>&order){
    if(cnt==3){
        order.push_back(s);
        return;
    }
    
    for(int i=0; i<3; i++){
        if(visited[i]==1)
            continue;
        visited[i]=1;
        s+=o[i];
        dfs(cnt+1, visited, o, s, order);
        visited[i]=0;
        s.pop_back();        
    }
}

long long solution(string expression) {
    
    // 숫자, 연산자 분리하기
    vector<long long> num; //숫자
    vector<char>oper; //연산자
    string a="";
    
    for(int i=0; i<expression.size(); i++){
        if(expression[i]>='0' && expression[i]<='9')
            a += expression[i];
        else{
            num.push_back(stoll(a));
            oper.push_back(expression[i]);
            a="";
        }
    }
    num.push_back(stoll(a));
    
    // 수식 우선순위 만들기
    vector<int>visited(3,0);
    vector<string>order; //수식 우선순위 담긴것
    vector<string>o;
    string s;
    o.push_back("+");
    o.push_back("-");
    o.push_back("*");
    
    dfs(0, visited, o, s, order);
    
    // 우선순위에 따라 계산하기
    vector<long long> cpnum;
    vector<char> cpoper;
    long long sum;
    long long answer = 0;
    
    for(int i=0; i<order.size(); i++){
        cpoper=oper;
        cpnum=num;
        for(int j=0; j<order[0].size(); j++){
            for(int k=0; k<cpoper.size(); k++){
                if(cpoper[k]==order[i][j]){
                    if(cpoper[k]=='+')
                        sum=cpnum[k]+cpnum[k+1];
                    else if(cpoper[k]=='-')
                        sum=cpnum[k]-cpnum[k+1];
                    else if(cpoper[k]=='*')
                        sum=cpnum[k]*cpnum[k+1];
                    
                    cpoper.erase(cpoper.begin()+k);
                    cpnum[k]=sum;
                    cpnum.erase(cpnum.begin()+k+1);
                    k--;
                }  
            }
        }
        if(cpnum[0]<0)
            cpnum[0]=cpnum[0]*(-1);
        if(answer<cpnum[0])
            answer=cpnum[0];
    }   
    
    return answer;
}
