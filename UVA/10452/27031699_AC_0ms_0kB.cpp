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
int tc, n, m, idx = 0;;
char g[26][26];
bool vis[26][26];
string road = "IEHOVA#";
string	dir[3] = {"forth", "left", "right" };
bool valid(int i, int j)
{
	return i >= 0 && j >= 0 && i < n&& j < m;
}
void dfs(int i, int j)
{
	if (idx == sz(road))return;
	vis[i][j] = 1;
	if(valid(i-1,j)&&!vis[i-1][j])
	if (g[i - 1][j] == road[idx])
	{
		
		if (idx < sz(road) - 1)
			cout << dir[0] << " ";
		else
			cout << dir[0];
		idx++;
		dfs(i - 1, j);
	}
	if (valid(i , j-1) && !vis[i][j - 1])
	if (g[i][j-1] == road[idx])
	{
	
		if (idx < sz(road) - 1)
			cout << dir[1] << " ";
		else
			cout << dir[1];
		idx++;
		dfs(i , j-1);
	}
	if (valid(i, j + 1))
	if (g[i][j+1] == road[idx] && !vis[i][j+1])
	{
		
		if (idx < sz(road) - 1)
			cout << dir[2] << " ";
		else
			cout << dir[2];
		idx++;
		dfs(i, j+1);
	}
}
int main()
{
	GOAT();
	cin >> tc;
	while (tc--)
	{
		memset(vis, 0, sizeof vis);
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for(int j=0;j<m;j++)
				cin >> g[i][j];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (g[i][j]=='@')
				{
					dfs(i,j);
				}
			}
		}
		cout << endl;
		idx = 0;
	}

}