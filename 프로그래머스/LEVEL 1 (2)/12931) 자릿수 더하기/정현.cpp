#include <iostream>
#include <string>

using namespace std;

// �̰� ���� ��
//int solution(int n)
//{
//    int answer = 0;
//
//    while (n != 0) // n �� 0�� �ƴ� ������ �ݺ��ؼ� ��� ���� �ڸ��� ������
//    {
		 // �ڸ��� ���� �ϳ��� answer�� ���ϱ�
         // ���� �ڸ��� �ϳ��� ������
//        answer += n % 10; // ���� �ڸ� ���ϰ�
//        n /= 10; // ������ ���� �ڸ� ����
//    }
//    return answer;
//}

// ���� ��ϲ� ��
int solution(int n)
{
	int ans = 0;

	string str = to_string(n); // �ڸ��� �� ����ϱ� ���� string���� ��ȯ

	for (int i = 0; i < str.size(); i++)
	{
		ans += str[i] -'0'; // ���ڷ� �ٲ��ݾ� �ƽ�Ű�ڵ� 48 ���ָ� �ش� ���ڰ� ���� ���ڰ� �Ǵ°ž�!!!! �̰ž�!!!!
	}
	return ans;
}