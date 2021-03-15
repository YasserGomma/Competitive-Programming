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
int ti=1, n, m;
vector <vector<int>>adj;
vector<int>topo, in,out;
bool can = 1;
void clear(int n)
{
	can = 1, ti = 1;
	adj.clear();
	topo.clear();
	in.clear();
	out.clear();
	out.resize(n + 1, 0);
	in.resize(n + 1, 0);
	adj.resize(n+1);
}
void dfs(int node)
{
	in[node] =ti++;
	for (auto ch : adj[node])
	{
		if (in[ch] && !out[ch])
			can = 0;
		if(!in[ch])dfs(ch);
	}
	out[node] = ti++;
	topo.push_back(node);
}
int main()
{
	COME_BACK();
	while (cin >> n>>m)
	{
		if (!m && !n)break;
		clear(n);
		while (m--)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		for (int i = 1; i <= n; i++)
		    if (!in[i])dfs(i);
		if (!can)cout << "IMPOSSIBLE" << endl;
		else
		{
			reverse(all(topo));
			for (auto it : topo)cout << it << endl;
		}
		
	}

}
