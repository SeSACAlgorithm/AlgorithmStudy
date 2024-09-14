#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    string st=to_string(x);
    char c;
    int temp;
    int ha=0;
    for(int i=0;i<st.size();i++)
    {
        c=st[i];
        temp=c-'0';
        ha+=temp;
    }
    if(x%ha==0)
    {
        answer=true;
    }
    else
    {
        answer=false;
    }
        
    return answer;
}
