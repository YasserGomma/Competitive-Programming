#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>	
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
#define all(v) ((v).begin()), ((v).end())	
#define sz(v) v.size()
#define endl "\n"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
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
	freopen("input.txt", "r", stdin);// freopen("out.txt", "w", stdout);
#endif
}
vector<vi>adj;
vector<bool> vis, clr;
int n;
void dfs(int src)
{
	
	    vis[src] = 1;
		for (auto ch : adj[src])
		{
			if (!vis[ch]) {
				vis[ch] = 1,clr[ch] = !clr[src];
				dfs(ch);
			}
		}
}
void rsz()
{
	adj.resize(n + 1);
	vis.resize(n + 1, 0);
	clr.resize(n + 1, 0);

}
int main()
{
	GOAT();
	cin >> n;
	rsz();
	for (int i = 0; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	clr[1] = 1;
	dfs(1);
	ll _0 = 0, _1 = 0;
	for (int i = 1; i <= n; i++)
		clr[i] ? _1++ : _0++;
	cout << (_0 * _1) - (n - 1) << endl;


}