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
int t, n, m;
vector <vector<int>>adj;
vector<bool>vis;
vector<int>color;
void clear(int n)
{
	adj.clear();
	vis.clear();
	color.clear();
	adj.resize(n);
	vis.resize(n, 0);
	color.resize(n, -1);
}
bool dfs(int node)
{
	vis[node] = 1;
	for (auto ch : adj[node])
	{
		if (!vis[ch])
		{
			color[ch] = !color[node];
			dfs(ch);
		}
		else if (color[ch] == color[node])
			return false;
	}
	return true;
}
int main()
{
	COME_BACK();
	while (cin >> n && n)
	{
		cin >> m;
		clear(n);
		while (m--)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		color[0] = 1;
		if (!dfs(0))cout << "NOT BICOLORABLE." << endl;
		else
			cout << "BICOLORABLE." << endl;
	}

}
