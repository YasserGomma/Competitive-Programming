#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
void yasser_gomma()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}
#define MEO yasser_gomma();
#define ll long long
#define r0 return 0;
#define all(v) ((v).begin()), ((v).end())
ll fact(ll n)
{
	ll f = 1;
	for (int i = 1; i <= n; i++)
	{
		f *= i;
	}
	return f;
}

int main()
{
	MEO
		int n;
	string a, b;
	cin >> n;
	map<string, string> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		if (m.count(a)==0)
			m[b] = a;
		else
		{
			m[b] = m[a]; m.erase(a);
		}
	}
	cout << m.size() << endl;
	map<string, string>::iterator it;
	for (it = m.begin(); it != m.end(); it++)
	{
		cout << it->second << ' ' << it->first << endl;
	}
}