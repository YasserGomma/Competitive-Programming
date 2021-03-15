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
int dx[4] = { -1,0,0,1};
int dy[4] = { 0,-1,1,0};
void GOAT()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
#endif
}
int n, m;
vector<vector<int>>adj;
bool vis[100001];
vector<int>topo;
void dfs(int node)
{
	vis[node] = 1;
	for (auto cur : adj[node])
	{
		if (!vis[cur])
		{
			dfs(cur);
		}
	}
	topo.push_back(node);
}
int main()
{
	memset(vis, 0, sizeof vis);
//	GOAT();
	cin >> n >> m;
	adj.resize(n + 1);
	for(int i=1;i<=m;i++)
	{
		int u, v; 
		cin >> u;
		while (u--) 
		{
			cin >> v;
			adj[i].push_back(v);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			dfs(i);

		}
	}
	vector<int>boss(n + 1);
	int pos = 0;
	for (int i=n-1;i>=0;i--)
	{
		boss[topo[i]] = pos;
		pos = topo[i];
	}
	for (int i = 1; i <= n; i++)cout << boss[i] << endl;

}