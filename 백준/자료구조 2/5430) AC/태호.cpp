#include <iostream>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

int t;

int main(void) 
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> t;

	while (t--)
	{
		string p; cin >> p;
		int n; cin >> n;
		string arr; cin >> arr;

		bool cond = false;
		bool err = false;
		string digit = "";

		deque<int> deq;
		

		for (char c : arr)
		{
			if (isdigit(c))
			{
				digit.push_back(c);
			}
			else
			{
				if (!digit.empty())
				{
					deq.push_back(stoi(digit));
					digit.clear();
				}
					
			}
		}

		if (!digit.empty())
			deq.push_back(stoi(digit));
			
		
		for (char c : p)
		{
			if(c == 'R')
				cond = !cond;

			else if (c == 'D')
			{
				if (deq.empty())
				{
					err = true;
					break;
				}

				cond ? deq.pop_back() : deq.pop_front();
			}
				
		}

		if (!err)
		{
			if (deq.empty())
			{
				cout << "[]\n";
			}
			else
			{
				cout << '[';
				
				if (cond)
				{
					while (deq.size() != 1)
					{
						cout << deq.back() << ',';
						deq.pop_back();
					}
				}
				else
				{
					while (deq.size() != 1)
					{
						cout << deq.front() << ',';
						deq.pop_front();
					}
				}

				cout << deq.front() << "]\n";
			}

		}
		else
			cout << "error\n";
		
	}
}
