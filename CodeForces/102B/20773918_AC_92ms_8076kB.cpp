#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define endl                         '\n'
#define Ceil(x,y)             ((x+y-1)/y)
#define sz(s)               (int)s.size()
#define RT(x)           return cout<<x,0;
#define mem(x,y)    memset(x,y,sizeof(x))
#define all(v) ((v).begin()), ((v).end())
#define vi                    vector<int>
#define pii                 pair<int,int>
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define forr(i, n) for (int i = 0; i < int(n); i++)
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
const double PI = acos(-1), EPS = 1e-7;
const int OO = 0x3f3f3f3f, N = 1e7 + 5, mod = 1e9 + 7;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll x, ll y) { return (!y) ? x : gcd(y, x % y); }
ll lcm(ll x, ll y) { return ((x / gcd(x, y)) * y); }
ll npr(ll n, ll r)
{
	ll ans = 1;
	for (ll i = n - r + 1; i <= n; i++)
	{
		ans *= i;
	}
	return ans;

}
ll ncr(ll n, ll r)
{
	ll res = 1, rfact = 2, x = 1;
	for (ll i = n - r + 1; i <= n; i++)
	{
		res *= i;
		res% rfact == 0 && rfact <= r ? res /= rfact, rfact++ : x = 1;
	}
	return res;

}
const int modall = 2520;
const double pi = 3.141592;
vector<ll>vec, vec1(1000009);

int main()
{
	string s;
	int ans = 0;
	cin >> s;
	while (s.size() != 1)
	{
		ll n = 0;
		stringstream ss;
		for (int i = 0; i < s.size(); i++)
			n += s[i] - '0';
		ss << n;
		ss >> s;
		ans++;
	}
	cout << ans << endl;
}