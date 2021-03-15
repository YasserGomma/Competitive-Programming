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
int n, m,cnt=0;
char g[100][100];
bool vis[100][100];
bool valid(int i, int j)
{
	return (i >= 0 && j >= 0 && i < n&& j < m);
}
bool can(int i, int j)
{
	for (int idx = 0; idx < 4; idx++)
		if (valid(i + dx[idx],j + dy[idx])&&g[i + dx[idx]][j + dy[idx]] == 'T')  return 0;
	return 1;
}
void dfs(int i, int j)
{
	vis[i][j] = 1;
	if (!can(i, j))return;
	for (int idx = 0; idx < 4; idx++)
	{
		int nx = i + dx[idx], ny = j + dy[idx];
		if (valid(nx, ny) && g[nx][ny] == 'G')cnt++, g[nx][ny] = '.';
		if (!vis[nx][ny] && valid(nx, ny)&& can(nx, ny) && g[nx][ny] != '#')dfs(nx, ny);
	}
}
int main()
{
	COME_BACK();
	while (cin >> n >> m)
	{
		swap(n, m);
		memset(vis, 0, sizeof vis);
		int x, y;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				cin >> g[i][j];
				if (g[i][j] == 'P')
					x = i, y = j;
			}
		dfs(x, y);
		cout << cnt << endl;
		cnt = 0;

	}
}