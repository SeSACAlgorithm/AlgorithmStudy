#include <iostream>

using namespace std;

int students[31];

int main(void)
{
    int total = 30;
    int callNum = 28;
    int num = 0;

    for (int i = 0; i < callNum; i++)
    {
        cin >> num;
        students[num]++;
    }

    for (int i = 1; i <= total; i++)
    {
        if (!students[i])
            cout << i << "\n";
    }
}