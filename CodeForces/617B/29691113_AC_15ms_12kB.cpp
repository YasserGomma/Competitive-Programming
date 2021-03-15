#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>	
using namespace std;
typedef long long ll;
#define all(v) ((v).begin()), ((v).end())	
#define sz(v) v.size()
#define endl "\n"
constexpr auto EPS = 1e-9;
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
ll gcd(ll a, ll b) { return (a) ? gcd(b % a, a) : b; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
int dx[8] = { 0,0,1,-1,1,-1,1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,-1,1 };
void GOAT()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
#endif
}
int main()
{
	GOAT();
	int n;
	cin >> n;
	vector<int>v(n);
	bool _1 = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		if (v[i])_1 = 1;
	}
	if (!_1)return cout << 0 << endl, 0;
	ll res = 1LL;
	for (int i = 0; i < n; i++)
	{
		if (v[i])
		{
			for (int j = i + 1; j < n; j++)
			{
				if (v[j])
				{
					res *= (j - i);
					break;
				}
			}
		}
	}
	cout << res << endl;
	ctime;

}