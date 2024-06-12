#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int x = 0;
    int y = 0;
    // ���ο� ���� ��, �� �� ���� 0��°�� ����
    for (int i = 0; i < sizes.size(); i++)
    {
        if (sizes[i][0] < sizes[i][1])
        {
            //swap ���� �� ���� ������ �ٲ��ش�!
            swap(sizes[i][0], sizes[i][1]);
        }
        // �迭 �� ���� ū ���� ã��~
        x = max(x, sizes[i][0]);
        y = max(y, sizes[i][1]);

        // �� �濡 ������ ����� �־���!!
        // ���� �� �߿��� �ִ밪, ū �� �߿��� �ִ밪 ã�Ƽ� ���ϴ�
       /* x = max(x, min(sizes[i][0], sizes[i][1]));
        y = max(y, max(sizes[i][0], sizes[i][1]));*/

        answer = x * y;
    }
    // 0��°���� ���� ū �� 1��°���� ���� ū �� ���ϱ�
    return answer;
}