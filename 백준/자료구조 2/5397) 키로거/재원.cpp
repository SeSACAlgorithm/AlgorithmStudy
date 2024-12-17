#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct password {
    password* before;
    char t;
    password* next;

    password(char c) : t(c), before(nullptr), next(nullptr) {}
};

int main() {
    int count;
    cin >> count;  // 테스트 케이스 수 입력

    vector<string> v;  // 결과 문자열을 저장할 벡터
    string s;

    for (int i = 0; i < count; i++) {
        cin >> s;

        // 가상의 헤더 노드 생성
        password* head = new password(0);
        password* current = head;

        for (char c : s) {
            if (c == '<') {  // 왼쪽 이동
                if (current->before)
                    current = current->before;
            }
            else if (c == '>') {  // 오른쪽 이동
                if (current->next)
                    current = current->next;
            }
            else if (c == '-') {  // 삭제
                if (current != head) {
                    password* temp = current;
                    current->before->next = current->next;
                    if (current->next)
                        current->next->before = current->before;
                    current = current->before;
                    delete temp;  // 메모리 해제
                }
            }
            else {  // 문자 삽입
                password* newNode = new password(c);
                newNode->before = current;
                newNode->next = current->next;
                if (current->next)
                    current->next->before = newNode;
                current->next = newNode;
                current = newNode;
            }
        }

        // 링크드 리스트 순회하며 결과 문자열 생성
        string result;
        password* temp = head->next;
        while (temp) {
            result += temp->t;
            temp = temp->next;
        }

        v.push_back(result);

        // 메모리 해제
        while (head) {
            password* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // 결과 출력
    for (const string& str : v) {
        cout << str << endl;
    }

    return 0;
}
