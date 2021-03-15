#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
#define mm(v) memset(v, 0, sizeof(v))
#define deb(x)   cout << "[" <<#x << "=" << x << "]" << endl
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
constexpr auto EPS = 1e-7;
const int mod = (int)1e9 + 7;
int dxn[] = { -1,-2,-2,-1,1,2,2,1 };
int dyn[] = { -2,-1,1,2,2,1,-1,-2 };
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
ll gcd(ll a, ll b) { return (a) ? gcd(b % a, a) : b; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
void nGu()
{
    std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
}
vector<vi>g;
vector<pii> dp;
int mx, node, n, s;

void rz(int n)
{
	g.clear();
	g.resize(n + 1);
	dp.clear();	
	dp.resize(n + 1);
}
int vis[102],vid;
void dfs(int u,int p)
{
	dp[u] = { 0,u };
	vis[u] = vid;
	for (auto ch : g[u])
	{
		if (vis[ch] != vid) dfs(ch, u);
		if (dp[u].first < dp[ch].first + 1)
			dp[u] = { dp[ch].first + 1,dp[ch].second };
		else if (dp[u].first == dp[ch].first + 1)
			dp[u].second=min(dp[u].second,dp[ch].second);

	}
}
int main()
{
    nGu();
	int cnt = 1;
    while (cin >> n &&n)
    {
		++vid;
        cin >> s;
		rz(n);
		int u, v;
		while (cin >> u >> v&&u&&v)
		{
			g[u].push_back(v);
			//g[v].push_back(u);
		}
		dfs(s,0);
		cout << "Case " << cnt++ << ": The longest path from " << s<< " has length " << dp[s].first << ", finishing at " << dp[s].second << "." << endl<<endl;

    }

    
}