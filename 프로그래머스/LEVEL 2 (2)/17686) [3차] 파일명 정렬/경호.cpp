#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Data
{
    string head = "";
    long long num = -1;
    
    string origin = "";
    int originIdx = 0;
    
    Data() {}
    
    Data(string input, int org_idx)
    {
        origin = input;
        originIdx = org_idx;
        
        int idx = 0;
        // head 추출
        for(int i = 0; i < input.size(); ++i)
        {
            if(isdigit(input[i]))
            {
                head = input.substr(0, i);
                idx = i;
                break;
            }
        }
        // num 추출
        for(int i = idx; i < input.size(); ++i)
        {
            if(false == isdigit(input[i]))
            {
                num = stoll(input.substr(idx, i - idx));
                break;
            }
        }
        if(num == -1)
            num = stoll(input.substr(idx, input.size() - idx));
        
        // head 대문자로 통일
        for(int i = 0; i < head.size(); ++i)
            if(islower(head[i]))
                head[i] = toupper(head[i]);
    }
};

vector<string> solution(vector<string> files) {
    vector<Data> datas(files.size());
    for(int i = 0; i < datas.size(); ++i)
        datas[i] = Data(files[i], i);
    
    sort(datas.begin(), datas.end(), [](Data a, Data b) {
        if(a.head != b.head)
            return a.head < b.head;
        if(a.num != b.num)
            return a.num < b.num;
        return a.originIdx < b.originIdx;
    });
    
    vector<string> answer(files.size());
    for(int i = 0; i < datas.size(); ++i)
        answer[i] = datas[i].origin;
    
    return answer;
}