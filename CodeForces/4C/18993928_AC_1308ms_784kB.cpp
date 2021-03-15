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
int main()
{
	ll a;
	string s;
	map<string, int>mp;
	cin >> a;
	while (a--)
	{
		cin >> s;
		mp[s]++;
		if (mp[s] < 2)
		{
			cout << "OK" << endl;
		}
		else
			cout << s << mp[s] - 1 << endl;
	}


}


	