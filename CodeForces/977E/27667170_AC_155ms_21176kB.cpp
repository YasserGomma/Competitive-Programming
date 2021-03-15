#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>	
using namespace std;
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
#define all(v) ((v).begin()), ((v).end())	
#define sz(v) v.size()
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
constexpr auto EPS = 1e-9;
const int mod = (int)1e9 + 7;
const double pi = acos(-1);
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
ll gcd(ll a, ll b) { return (a) ? gcd(b % a, a) : b; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
void GOAT()
{
	std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
vector<vi>g;
vector<int>vis;
int n, m;
bool cycle;
int ed = 0,nd = 0;
bool dfs(int node)
{
	bool ret = true;
	vis[node] = 1;
	if (sz(g[node]) != 2) ret=false;
	for (auto ch : g[node])
	{
		if (!vis[ch])  ret&=dfs(ch);
	}
	return ret;
}
int main()
{
	GOAT();
	cin >> n >> m;
	g.resize(n);
	vis.resize(n);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			ans += dfs(i);
		}
	}
	cout << ans << endl;

}