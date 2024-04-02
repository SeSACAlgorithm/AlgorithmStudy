#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int num_cnt;
	cin >> num_cnt;
	vector<int> list;

	for(int i = 0 ; i < num_cnt; i++)
	{
		int value;
		cin >> value;
		list.push_back(value);
	}

	cout << "1" << " ";

	int index = list[0];
	list[0] = 0;
	int cnt = 0;

	for (int i = 1; i < list.size(); i++) {
		int count = index;
		if (index > 0) {
			// 종이 값이 양수일때
			while (count > 0) {
				cnt = (cnt + 1 > list.size() - 1) ? 0 : cnt + 1;
				if (list[cnt] != 0) count--;
			}
		}
		else {
			// 종이 값이 음수 일때
			count *= -1; // 음수 값을 양수로 전환
			while (count > 0) {
				cnt = (cnt - 1 < 0) ? list.size() - 1 : cnt - 1;
				if (list[cnt] != 0) count--;
			}
		}
		index = list[cnt];
		list[cnt] = 0;
		cout << cnt + 1 << " ";
	}

	return 0;

}

