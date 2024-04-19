// 문제 분석
/*
들어오고 나간거 answer에 담기
change하면 닉네임이 바뀜 / 다시 들어올 때 닉네임 바꾸면 바뀜
=> 최종적으로 알림을 찍을 때 최종 닉네임으로 나와야함!

유의해야할 케이스
record = ["Enter uid1234 Rion", "Change uid1234 Hi", "Leave uid1234", "Enter uid1234 Prodo"]
answer = ["Prodo님이 들어왔습니다.", "Prodo님이 나갔습니다.", "Prodo님이 들어왔습니다."]

라이언 들어옴
라이언 닉변 -> 하이
라이언 나감
라이언 -> 프로도로 바꿔서 들어옴

프로도 들어옴
프로도 나감
프로도 들어옴
*/

#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    string command = "";
    string userid = "";
    string nickname = "";

    map<string, string> db; // userid, nickname

    for(int i = 0; i < record.size(); i++)
    {
        // Enter userid nickname
        // Change userid nickname
        if(record[i][0] == 'E' || record[i][0] == 'C')
        {
            stringstream data(record[i]);
            data >> command >> userid >> nickname;
            db[userid] = nickname;
        }
    }

    for(string message : record)
    {
        // Enter userid nickname
        if(message[0] == 'E')
        {
            stringstream data(message);
            data >> command >> userid >> nickname;

            answer.push_back(db[userid] + "님이 들어왔습니다.");
        }

        // Leave userid
        else if(message[0] == 'L')
        {
            stringstream data(message);
            data >> command >> userid;

            answer.push_back(db[userid] + "님이 나갔습니다.");
        }
    }

    return answer;
}