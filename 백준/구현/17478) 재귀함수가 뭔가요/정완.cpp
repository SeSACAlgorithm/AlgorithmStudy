#include <iostream>
#include <string>

using namespace std;

void recursive(int n, int cur)
{
    for(int i=0; i<cur; i++)
        cout << "____";

    cout << "\"����Լ��� ������?\"\n";

    if(cur == n)        // �ݺ� ���� �޼� ��
    {
        for (int i = 0; i < cur; i++)
            cout << "____";
        cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
    }
    
    else
    {
        for (int i = 0; i < cur; i++) cout << "____";
            cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";

        for (int i = 0; i < cur; i++) cout << "____";
            cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
            
        for (int i = 0; i < cur; i++) cout << "____";
            cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";

        recursive(n, cur+1);
    }

    for (int i = 0; i < cur; i++)
        cout << "____"; 

    cout << "��� �亯�Ͽ���.\n";
}

int main(void)
{
    int n;
    cin >> n;

    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    recursive(n, 0);

    return 0;
}