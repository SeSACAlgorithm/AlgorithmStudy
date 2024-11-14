#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    
	int answer = dist.size() + 1;
	int size = weak.size();

	for (int i = 0; i < size; ++i)
		weak.push_back(weak[i] + n);

	for (int st = 0; st < size; ++st)
	{
		int asd = 0;

		do
		{
			int cnt = 1;
			int cur = weak[st] + dist[cnt - 1];

			for (int i = st; i < st + size; ++i)
			{
				if (cur < weak[i])
				{

					++cnt;
					if (cnt > dist.size())
						break;

					cur = dist[cnt - 1] + weak[i];
				}
			}

			answer = min(answer, cnt);

		} while (next_permutation(dist.begin(), dist.end()));


	}


	return (answer == dist.size() + 1 ? -1 : answer);
}
