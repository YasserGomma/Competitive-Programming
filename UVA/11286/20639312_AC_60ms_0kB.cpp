#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define sz(s)	(int)(s.size())
#define all(v) v.begin(),v.end()
typedef	long long ll;
int main()
{
	ll n;
	while (cin >> n&&n)
	{
		map<vector<int>, int>mp;
		vector<int>v(5);
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < 5; i++)cin >> v[i];
			sort(all(v)); mp[v]++;
		}
		map<int, int>mp1;
		int mx = INT_MIN;
		for (auto it : mp)
		{
			mp1[it.second]++;
			mx = max(mx, it.second);
		}
				cout << mx*mp1[mx] << endl;
			
	}
}