int n, m;
int arr[10];
int idx[10];

void func(int cur)
{
	if(cur == m)
	{
		for(int i = 0; i < m; ++i)
			cout << arr[i] << ' ';

        cout << '\n';
		return;
	}

    for(int i = 0; i < n; ++i)
    {
        arr[cur] = idx[i];
        func(cur + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; ++i)
        cin >> idx[i];

    sort(idx, idx + n);

    func(0);
}
