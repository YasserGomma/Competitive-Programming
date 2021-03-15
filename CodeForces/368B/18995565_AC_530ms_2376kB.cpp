/*
		 /\_/\
   )____/ o o \
  /~____  =?= /
 (______)__m_m)
 MEOOO!!!
 */
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
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
ll freq[100009];
ll arr[100009];
ll fr[100009];
int main()
{
	ll n, m;
	cin >> n >> m;
	for (int i = 1; i <=n; i++)
	{
		cin >> arr[i];
	}
	for (int i = n; i> 0; i--)
	{
		if (freq[arr[i]] == 0)
			fr[i] = fr[i + 1] + 1;
		else
			fr[i] = fr[i + 1];
		freq[arr[i]]++;
		
	}
	while (m--)
	{
		ll p;
		cin >> p;
		cout << fr[p] << endl;
	}
}


	