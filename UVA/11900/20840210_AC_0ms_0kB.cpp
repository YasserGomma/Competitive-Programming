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
void factors(ll n, vector<int>& v)
{
	for (int i = 1; i < sqrt(n); i++) {
		if (n % i == 0) {
			v.push_back(i);
			v.push_back(n / i);
		}
	}
		if (pow((int)sqrt(n), 2) == n)
			v.push_back(sqrt(n));
}
int main()
{
	yasser();
	int t;
	cin >> t;
	int idx = 1;
	while(t--)
	{
		int n,b, q;
		cin >> n >> b>> q;
		vector<int>v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		int con = 0, p = 0, sum = 0;
		for (int i = 0; i < n; i++)
		{
			
			if (con + 1 <= b && sum + v[i] <= q)
			{
				con++;
				sum += v[i];
			}
			else break;
			
		}
		cout << "Case "<<idx << ": " << con << endl;
		idx++;
	}
}
