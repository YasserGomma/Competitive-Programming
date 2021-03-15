#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef	long long ll;
int main()
{

	map<int, int>mp;
	string s;
	while (cin >> s)
	{
		if (s == "#")
			break;
		int n, k;
		cin >> n >> k;
		mp[n] = k;
	}
	int n;
	cin >> n;
	vector<int>v;
	for (int i = 1; i <= 30000; i++)
	{
		for (auto it : mp)
		{
			if (i % it.second == 0)
				v.push_back(it.first);
		}
	}
	for (int i = 0; i < n; i++)
		cout << v[i] << endl;
}