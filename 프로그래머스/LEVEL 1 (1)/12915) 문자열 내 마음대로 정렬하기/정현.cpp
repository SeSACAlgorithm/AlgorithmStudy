#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// sort(strings.begin(),strings.end(),compare) sort() �Լ����� 3��° ���ڸ� ���� ���� �Լ��� ������
// �� ����� ������ �� �ִ�!!!
int a;
bool compare(string b, string c) {
    // b���ڿ�, c���ڿ��� a��° ���� ���ؼ� ������ b,c ���ؼ� �������� ����
    if (b[a] == c[a]) {
        return b < c;
    }
    else
        // ���� �ʴٸ� a��° ���� �������� �������� ����!!!
        return b[a] < c[a];
}
vector<string> solution(vector<string> strings, int n) {
    a = n;
    sort(strings.begin(), strings.end(), compare);
    return strings;
}