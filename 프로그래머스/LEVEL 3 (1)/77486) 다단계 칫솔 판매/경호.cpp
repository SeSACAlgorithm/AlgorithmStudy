#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    map<string, int> count;
    
    map<string, string> ref;
    for(int i = 0; i < enroll.size(); ++i)
        if(referral[i] != "-")
            ref[enroll[i]] = referral[i];
    
    for(int i = 0; i < seller.size(); ++i)
    {
        string cur = seller[i];
        int money = amount[i] * 100;
        int charge = money / 10;
        
        while(false == cur.empty())
        {
            count[cur] += money - charge;
            money = charge;
            charge = money / 10;
            if(money == 0) break;
            
            cur = ref[cur];
        }
    }
    
    vector<int> answer(enroll.size());
    for(int i = 0; i < enroll.size(); ++i)
        answer[i] = count[enroll[i]];
        
    return answer;
}