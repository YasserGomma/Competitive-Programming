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
void yasser()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
#endif
}
bool isPrime(int n)
{
	int i;
	for (i = 2; i <= sqrt(n); ++i) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}
void primeFactors(ll n, vector<int>& v)
{
	while (n % 2 == 0)
	{
		v.push_back(2);
		n = n / 2;
	}
	for (ll i = 3; i * i < n; i += 2)
	{
		while (n % i == 0)
		{
			if (isPrime(i))
				v.push_back(i);
			else
			{
				v.push_back(sqrt(i));
				v.push_back(sqrt(i));



			}
			n = n / i;
		}
	}
	if (n > 2)
	{
		if (isPrime(n))
			v.push_back(n);
		else {
			v.push_back(sqrt(n));
			v.push_back(sqrt(n));
		}
	}
}
int main()
{
	yasser();
	int x;
	while (cin >> x && x)
	{
		bool neg = 0;
		if (x < 0) {
			neg = 1;
			x *= -1;
		}
		vector<int>v;
		primeFactors(x, v);
		/*cout << sz(v) << endl;*/

		if (neg)
		{
			x *= -1;
			cout << x << " =";
			cout << " -1 x ";
		}
		else
			cout << x << " = ";
		for (int i = 0; i < sz(v) - 1; i++)
			cout << v[i] << " x ";
		cout << v[sz(v) - 1] << endl;
	}
}
