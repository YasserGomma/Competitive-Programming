/*(وَمَا تَوْفِيقِي إِلَّا بِاللَّه) */
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
#define all(v) ((v).begin()), ((v).end())	
#define sz(v) v.size()
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
constexpr auto EPS = 1e-7;
const int MOD = (int)1e9 + 7;
int dxn[] = { -1,-2,-2,-1,1,2,2,1 };
int dyn[] = { -2,-1,1,2,2,1,-1,-2 };
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
ll gcd(ll a, ll b) { return (a) ? gcd(b % a, a) : b; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
void COME_BACK()
{
	std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
vector<vector<int>>g;
int dp[5009][5009];
void rz(int n)
{
	g.clear();
	g.resize(n+9);
}
int dfs(int u, int par)
{
	int& ret = dp[u][par];
	if (~ret)return ret;
	ret = 0;
	for (auto& it : g[u])
	{
		if (it != par)
			ret = max(ret, 1 + dfs(it, u));
	}
	return ret;
}
int main()
{
	COME_BACK();
	int n;
	while (cin >> n)
	{
		rz(n + 1);
		for (int i = 1; i <= n; i++)
		{
			int t; cin >> t;
			while (t--)
			{
				int v; cin >> v;
				g[i].push_back(v);
				g[v].push_back(i);
			}
		}
		memset(dp, -1, sizeof dp);
		vi len(n + 1);
		int mnl = INT_MAX, mxl = -1;
		for (int i = 1; i <= n; i++)
		{
			int hi = dfs(i, -1);
			mnl = min(mnl, hi);
			mxl = max(mxl, hi);
			len[i] = hi;
		}
		vi mN, mX;
		for (int i = 1; i <= n; i++)
			if (len[i] == mnl)mN.push_back(i);
		for (int i = 1; i <= n; i++)
			if (len[i] == mxl)mX.push_back(i);
		cout << "Best Roots  : ";
		cout << mN[0];
		for (int i = 1; i < sz(mN); i++)cout << " " << mN[i];
		cout << endl;
		cout << "Worst Roots : ";
		cout << mX[0];
		for (int i = 1; i < sz(mX); i++)cout << " " << mX[i];
		cout << endl;
		
	}
}