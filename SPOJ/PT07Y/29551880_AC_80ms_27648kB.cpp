#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
#define pb push_back
#define mm(v) memset(v, 0, sizeof(v))
#define deb(x)   cout << "[" <<#x << "=" << x << "]" << endl
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
constexpr auto EPS = 1e-7;
const int mod = (int)1e9 + 7;
int dxn[] = { -1,-2,-2,-1,1,2,2,1 };
int dyn[] = { -2,-1,1,2,2,1,-1,-2 };
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
ll gcd(ll a, ll b) { return (a) ? gcd(b % a, a) : b; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
void nGu()
{
    std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
}
int n, m, t;
vector<int> v[1000007];
bool vis[1000007];
bool dfs(int u, int par)
{
	vis[u] = 1;
	for (int it : v[u])
	{
		if (it != par && vis[it])
			return false;
		if (!vis[it])
		{
			if (!dfs(it, u))
				return false;
		}
	}
	return true;
}
bool check(int n) {
	bool ret = true;
	for (int v = 1; v <= n; ++v) {
		if (!vis[v])
			return false;
	}
	return true;
}
int main()
{

	nGu();
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);

	}
	bool con = 1;
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
			con = 0;
	}
	if (dfs(1, 0) && check(n))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
