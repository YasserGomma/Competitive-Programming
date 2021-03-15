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
const double pi = 3.141592;
int main()
{
	
	int n, q,idx = 1;
	while (cin >> n >> q && n && q)
	{
		int  frq[100009];
		vector<int>arr(n + 1);
		memset(frq, 0, sizeof(frq));
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			frq[arr[i]]++;
		}
		sort(all(arr));
		cout << "CASE# " << idx << ":" << endl;
		while (q--)
		{
			int x;
			cin >> x;
			if (frq[x])
			{
				int idd = lower_bound(all(arr), x) - arr.begin();
				cout << x << " found at " << idd  << endl;
			}
			else
				cout << x << " not found" << endl;
			

		}
		idx++;
	}

}
