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
vector<vi>adj;
vector<bool>vis;
vector<tuple<int,int,int>>v;
int n, t;
void build_graph()
{
	adj.clear();
	adj.resize(n);
	for (int i = 0; i < n; i++) {
		int x = get<0>(v[i]), y = get<1>(v[i]);
		for (int j = 0; j < n; j++)
		{
			int xx = get<0>(v[j]), yy = get<1>(v[j]), d = get<2>(v[j]);
			if (x >= xx - d && x <= xx + d && y >= yy - d && y <= yy + d)
				adj[j].push_back(i);

		}
	}
}
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
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int x, y, d;
			cin >> x >> y >> d;
			v.push_back({ x,y,d/2});
		}
		build_graph();
		vis.resize(n,0);
		vector<int>destroyed;
		for (int i = 0; i < n; i++)
		{
			if (!vis[i])
			{
				dfs(i);
				destroyed.push_back(i);
			}
		}
		vis.clear();
		vis.resize(n);
		int ans = 0;
		//for (auto it : destroyed)cout << it << " ";
		reverse(all(destroyed));
		for (auto node : destroyed)
		{
			if (!vis[node])
			{
				ans++;
				dfs(node);
			}
		}
		cout << ans << endl;
		adj.clear();
		vis.clear();
		v.clear();
	}
}