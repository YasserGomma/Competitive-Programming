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
vector<vi>adj;
vector<int>order,cnt,frs;
void dfs(int node)
{
	order.push_back(node);
	frs[node] = sz(order)-1;
	cnt[node] = 1;
	for (auto ch : adj[node])
	{
		dfs(ch);
		cnt[node] += cnt[ch];
	}
}
int main()
{
	COME_BACK();
	int n, q;
	cin >> n >> q;
	adj.resize(n + 1);
	cnt.resize(n + 1);
	frs.resize(n + 1);
	for (int i = 2; i <= n; i++)
	{
		int u; cin >> u;
		adj[u].push_back(i);
	}
	dfs(1);
	while (q--)
	{
		int u, k;
		cin >> u >> k;
		if (cnt[u]<k)cout << -1 << endl;
		else
		{
			cout << order[frs[u] + k - 1] << endl;
		}
	}

}
