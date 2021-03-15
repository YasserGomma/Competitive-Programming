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
int n, m;
vector<bool>vis;
vector<vi>adj;
vector<int>topo;
void dfs(int node)
{
	vis[node] = 1;
	for (auto ch : adj[node])
	{
		if (!vis[ch])
			dfs(ch);
	}
}
int main()
{
	COME_BACK();
	int n, m, src;
	cin >> n >> m >> src;
	adj.resize(n + 1);
	for (int i = 1; i <= m; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}
	vis.resize(n + 1);
	dfs(src);
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			dfs(i);
			topo.push_back(i);
		}
	}
	vis.clear();
	vis.resize(n + 1);
	int ans = 0;
	reverse(all(topo));
	for (auto node : topo)
	{
		if (!vis[node] && node != src)
		{
			ans++;
			dfs(node);
		}
	}
	cout << ans << endl;
}
