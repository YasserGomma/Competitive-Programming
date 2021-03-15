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
int n, m, ans = 0;
vector<vi>g(105);
vector<int> vis(105), clr(105);
void dfs(int u, int par,int c)
{
	vis[u] = 1;
	clr[u] = c;
	for (auto ch : g[u])
	{
		if (ch==par)continue;
		if (!vis[ch])dfs(ch, u, !c);
		if (clr[ch] == clr[u]) {
			ans++;
		}
	}
}
int main()
{
	GOAT();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <=n; i++)
	{
		if (!vis[i])
		{
			dfs(i, -1, 0);
		}
	}
	ans /= 2;
	if ((n - ans)&1)ans++;
	cout << ans << endl;
}