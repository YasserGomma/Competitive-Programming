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
int main()
{
	GOAT();
	int n, m;
	cin >> n >> m;
	vector<set<int>>adj(100009);
	vector<int>color(100009);
	int mnc = INT_MAX;
	for (int i = 0; i < n; i++)cin >> color[i],mnc=min(mnc,color[i]);
	int mx = 0;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		if (color[u] != color[v]) 
		{
			adj[color[u]].insert(color[v]);
			adj[color[v]].insert(color[u]);
			mx = max(mx, (int)max(sz(adj[color[u]]), sz(adj[color[v]])));
		}
		
	}
	vector<int>ans;
	for (int i = 0; i < 1e5; i++)
	{
		if (sz(adj[color[i]]) == mx)ans.push_back(color[i]);
	}
	if (*min_element(all(ans)))
		cout << *min_element(all(ans));
	else
		cout << mnc;

}