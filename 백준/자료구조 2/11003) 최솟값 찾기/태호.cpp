#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int n, l;

int main(void) 
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> l;

	vector<int> vec(n);

	for(int i = 0; i < n; ++i)
		cin >> vec[i];

    deque<pair<int, int>> deq;

    for (int i = 0; i < n; ++i) {
		
		while(!deq.empty() && deq.front().second <= i - l)
			deq.pop_front();

		while(!deq.empty() && deq.back().first > vec[i])
			deq.pop_back();

		deq.push_back({vec[i], i});

		cout << deq.front().first << ' ';
    }
}
