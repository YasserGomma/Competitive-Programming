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
vi vis, topo;
void rz(int n)
{
	topo.clear();
	vis.clear();
	g.clear();
	vis.resize(n+1);
	g.resize(n+1);
	topo.resize(n + 1);

}
int mx = 0, lng = 0;
void dfs(int node,int par,int cost=0)
{
	if (cost> mx) {
		mx = cost;
		lng = node;
	}
	for (auto it : g[node])
	{
		if (it!=par)
		{
			
			dfs(it,node,cost+1);
		}
	}
	

}
int main()
{
	GOAT();
	int n, m;
    	cin >> n;
		rz(n);
		for (int i = 0; i < n-1; i++)
		{
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);

			
		}
		dfs(1,-1,0);
		//cout << mx << " " << lng << endl;
		mx = 0;
		dfs(lng, -1, 0);
		cout << mx << endl;;
}