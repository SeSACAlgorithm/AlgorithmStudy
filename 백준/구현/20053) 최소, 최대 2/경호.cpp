#include <iostream>

using namespace std;

void MinAndMax(int count, int& min, int& max)
{
    int num = 0;
    for(int i = 0; i < count; ++i)
    {
	cin >> num;
	if (min > num) min = num;
	if (max < num) max = num;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
	int count;
	cin >> count;

	int min = 10000000, max = -10000000;
	MinAndMax(count, min, max);
	cout << min << " " << max << "\n";
    }
}