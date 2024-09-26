#include <string>
#include <vector>
#include <unordered_map>
#include <sstream> // stringstream을 사용하기 위한 헤더 파일
using namespace std;

struct player {
    string type;
    string id;
};

// 입출력 메시지 생성 함수
string makeresult(const string& type, const string& name) {
    if (type == "Enter") {
        return name + "님이 들어왔습니다.";
    } else if (type == "Leave") {
        return name + "님이 나갔습니다.";
    }
    return "";
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<player> p; // 행동 기록 저장
    unordered_map<string, string> id_name_map; // id-이름 매핑 저장

    // 기록을 처리하는 부분
    for (int i = 0; i < record.size(); i++) {
        stringstream ss(record[i]);//record[i] 를 공백기준으로 쪼개
        string type, id, name;
        ss >> type >> id;//각각 타입과 id 저장 

        if (type == "Enter" || type == "Change") {
            ss >> name; // Enter와 Change에서는 name을 추가로 가져옴
            id_name_map[id] = name; // id에 대한 최신 이름으로 업데이트
        }

        if (type == "Enter" || type == "Leave") {
            p.push_back({type, id}); // 행동 기록 추가
        }
    }

    // 최종 메시지 생성
    for (int i = 0; i < p.size(); i++) {
        string type = p[i].type;
        string id = p[i].id;
        answer.push_back(makeresult(type, id_name_map[id])); // 최신 이름을 기반으로 메시지 생성
    }

    return answer;
}
