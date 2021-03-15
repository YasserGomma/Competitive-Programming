#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>	
using namespace std;
typedef long long ll;
#define bay_bay return 0;
#define fori(n) for(int i=0;i<n;++i)
#define for1(n) for(int i=1;i<=n;i+=3)
#define all(v) ((v).begin()), ((v).end())	
#define sz(v) v.size()
#define endl "\n"
constexpr auto EPS = 1e-9;
#define ff fflush(stdout);
const int mod = 1000000007;
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
void GOAT()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
#endif
}
int n, m;
int v[21],c[21];
ll x,t,mn=LLONG_MAX;
void solve(int idx, ll va, ll ca)
{
	if (va >= x)
	{
		mn = min(mn, ca);
		return;
	}	
	if (idx == n)
		return;
	solve(idx + 1, va + v[idx] * t, ca + c[idx]);
	solve(idx + 1, va, ca);
}
	
int main()
{
	GOAT();
	cin >> n;
	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i] >> c[i];
	}
	cin >> m;
	for (int i = 1; i <= m; i++)
	{

		cin>>x>>t;
		mn = LLONG_MAX;
		solve(0, 0, 0);
		cout << "Case " << i << ": ";
		if (mn != LLONG_MAX) cout << mn << endl;
		else cout << "IMPOSSIBLE" << endl;
		
	}

        
}