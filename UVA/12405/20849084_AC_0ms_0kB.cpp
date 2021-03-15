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
vector<ll>fac(1000009);
void  sieve_v1() {
	for (int i = 1; i <= 1000009; i++) {
		
			for (int j = i ; j <=1000000; j += i) 
			{
				fac[j]++;
			}
	}
}
int main()
{
	yasser();
	int T, C = 1;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<char> field(n + 2, '#');
		for (int i = 0; i < n; ++i)
			cin >> field[i];

		int scarecrows = 0;
		for (int i = 0; i < n; ++i)
		{
			if (field[i] == '.')
			{
				field[i] = field[i + 1] = field[i + 2] = '#';
				++scarecrows;
			}
		}
		cout << "Case "
			<< C++
			<< ": "
			<< scarecrows
			<< endl;
	}

}
