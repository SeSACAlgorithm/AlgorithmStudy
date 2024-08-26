#include<bits/stdc++.h>

using namespace std;

unordered_map<string, vector<string>> adj;
unordered_map<string, int> indgree;
unordered_map<string, string> depth;

int main()
{
	int n, m, k = 0; cin >> n;

	vector<string> playerName(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> playerName[i];
		adj[playerName[i]] = vector<string>();
		depth[playerName[i]] = string();
		indgree[playerName[i]] = 0;
	}
		

	cin >> m;

	for (int i = 0; i < m; ++i)
	{
		string a, b; 
		cin >> a >> b;

		adj[b].push_back(a);
		++indgree[a];
	}

	set<string> names;
	queue<string> q;

	for (auto& player : playerName)
	{
		if (!indgree[player])
		{
			q.push(player);
			names.insert(player);
		}
	}

	while (!q.empty())
	{
		string cur = q.front(); 
		q.pop();

		for (const auto& elem : adj[cur])
		{
			depth[elem] = cur;
			--indgree[elem];

			if(!indgree[elem])
				q.push(elem);
		}
	}
		
	map<string, pair<set<string>, int>> M;

	for (auto& elem : depth)
	{
		auto iter = M.find(elem.second);

		if (iter == M.end())
		{
			set<string> temp;
			temp.insert(elem.first);
			pair<set<string>, int> a(temp, 1);
			M.emplace(elem.second, a);
		}
		else
		{
			iter->second.first.insert(elem.first);
			++iter->second.second;
		}
			
	}

	cout << names.size() << '\n';
	for(auto& elem : names)
		cout << elem << ' ';

	cout << '\n';

	
	sort(playerName.begin(), playerName.end());

	for(int i = 0; i < playerName.size(); ++i)
	{
		int count = M[playerName[i]].second;
		set<string> childName = M[playerName[i]].first;
		
		cout << playerName[i] << ' ';
		cout << count << ' '; 
		
		for (auto& elem : childName)
			cout << elem << ' ';


		cout <<  '\n';
	}

	int test = 0;


	return 0;
}
