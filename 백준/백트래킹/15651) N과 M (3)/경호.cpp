#include <iostream>
#include <vector>

using namespace std;

void back_tracking(int N, int M, int layer, vector<int>& data)
{
	if(layer == M)
	{
        for(const int& num : data)
			cout << num << " ";
        cout << "\n";
        return;
	}

    for(int i = 0; i < N; ++i)
    {
        data[layer] = i + 1;
        back_tracking(N, M, layer + 1, data);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> data(M);
    back_tracking(N, M, 0, data);
}