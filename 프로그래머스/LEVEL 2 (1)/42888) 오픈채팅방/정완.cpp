#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    
    vector<string> ans;     // 최종 결과
    map<string, string> m;  // 사용자 ID, 닉네임 매핑
    
    string enter = "님이 들어왔습니다.";
    string leave = "님이 나갔습니다.";
    
    // 1. 사용자 ID랑 닉네임 업데이트
    for(int i=0; i<record.size(); i++)
    {
        vector<string> v;
        string str;

        for(int j=0; j<record[i].size(); j++)
        {
            if(record[i][j] == ' ') // 공백인 경우 문자열 백터에 추가 후 초기화
            {
                v.push_back(str);
                str = "";
            }

            else    // 문자인 경우 현재 문쟈열에 추가
            {
                str += record[i][j];

                if(j+1 == record[i].size()) // 문자열 마지막 문자 도달한 경우 벡터에 추가
                    v.push_back(str);
            }
        }

        if(record[i][0] == 'E') // Enter
        {
            if(m.find(v[1]) != m.end()) // ID가 이미 존재하는 경우 업데이트
                m[v[1]] = v[2];

            else    // 새 ID 추가
                m.insert(pair<string, string>(v[1], v[2]));
        }

        else if(record[i][0] == 'C')    // Change
            m[v[1]] = v[2];
    }
    
    // 2. 최종 결과
    for(int i=0; i<record.size(); i++)
    {
        vector<string> v;
        string str;
        
        for(int j=0; j<record[i].size(); j++)
        {
            if(record[i][j] == ' ') // 공백인 경우 문자열 벡터에 추가 후 초기화
            {
                v.push_back(str);
                str = "";
            }

            else    // 문자인 경우 현재 문자열에 추가
            {
                str += record[i][j];

                if(j+1 == record[i].size()) // 문자열 마지막 문자 도달한 경우 벡터에 추가
                    v.push_back(str);
            }
        }
        
        if(record[i][0] == 'E')
        ans.push_back(m[v[1]] + enter);
    
        else if(record[i][0] == 'L')
            ans.push_back(m[v[1]] + leave);
    }
    
    return ans;
}
