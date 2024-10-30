#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
       vector<int> answer;
    unordered_map<string, string> parent;
    unordered_map<string, int> res;

    /*
        john -> 센터
        마리 -> 센터
        에드워드 -> 마리 -> 센터
        샘 -> 에드워드 -> 마리 -> 센터
        에밀리 -> 마리 -> 센터
        제이미 -> 마리 -> 센터
        토드 -> 제이미 -> 마리 -> 센터
        영 -> 에드워드 -> 마리 ->센터

        이 때 10퍼씩 까보자잉
    */



    for (int i = 0; i < referral.size(); ++i)
        parent[enroll[i]] = referral[i];

    for (int i = 0; i < seller.size(); ++i)
    {
        int point = amount[i] * 100;
        string me = seller[i];

        res[me] += point;

        while (me != "-" && point > 9)
        {
            point /= 10;
            res[parent[me]] += point;
            res[me] -= point;
            me = parent[me];

        }
    }

    for (int i = 0; i < enroll.size(); ++i)
        answer.push_back(res[enroll[i]]);


    return answer;
}
