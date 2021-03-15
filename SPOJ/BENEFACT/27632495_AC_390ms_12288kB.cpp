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
vector<vi>g;
vi vis, topo;
int mx = 0, lng = 0;
map<pii, int>mp;
void rz(int n)
{
	vis.clear();
	g.clear();
	vis.resize(n + 1);
	g.resize(n + 1);
	mp.clear();
	mx = lng = 0;
}
void dfs(int node, int par, int cost = 0)
{
	if (cost > mx) {
		mx = cost;
		lng = node;
	}
	for (auto it : g[node])
	{
		if (it != par)
		{
			dfs(it, node, cost + mp[{it, node}]);

		}
	}


}
int main()
{
	//COME_BACK();
	int t;
	cin >> t;
	while (t--)
	{
		int n;cin >> n;
		rz(n);
		for (int i = 1; i < n; i++)
		{
			int u, v,cost;
			cin >> u >> v>>cost;
			g[u].push_back(v);
			g[v].push_back(u);
			mp[{u, v}] = mp[{v, u}] = cost;
		}

		dfs(1, -1, 0);
		mx = 0;
		dfs(lng, -1, 0);
		cout << mx << endl;
	}
	
	
	
}