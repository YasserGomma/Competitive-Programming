#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <assert.h>
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
vector<ll>v1;
vector<ll>v2;
vector<ll>v3;
int main()
{
	MEO
		ll a;
	
	ll x;
	cin >> a;
	for (int i = 0; i < a; ++i)
	{
		cin >> x;
		v1.push_back(x);
	}
	a--;
	for (int i = 0; i <a; ++i)
	{
		cin >> x;
		v2.push_back(x);
	}
	a--;
	for (int i = 0; i < a; ++i)
	{
		cin >> x;
		v3.push_back(x);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	sort(v3.begin(), v3.end());
	a += 2;
	for (int i = 0; i < a; ++i)
	{
		if (v1[i] != v2[i]) {
			cout << v1[i] << endl;
			break;
		}
	}
	a--;
	for (int i = 0; i < a; ++i)
	{
		if (v2[i] != v3[i]) {
			cout << v2[i] << endl;
			break;
		}
	}
}