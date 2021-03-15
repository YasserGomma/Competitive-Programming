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
int tc = 1, n;
char g[26][26];
bool vis[26][26];
bool valid(int i, int j)
{
	return i >= 0 && j >= 0 && i < n&& j < n;
}
void dfs(int i, int j)
{
	vis[i][j] = 1;
	for (int idx = 0; idx < 8; idx++)
	{
		int ni = i + dx[idx], nj = j + dy[idx];
		if (valid(ni, nj) && !vis[ni][nj] && g[ni][nj] == '1')
		{
			dfs(ni, nj);
		}

	}
}
int main()
{
	GOAT();
	while (cin >> n)
	{
		memset(vis, 0, sizeof vis);
		for (int i = 0; i < n; i++)
			for(int j=0;j<n;j++)
				cin >> g[i][j];
		int cntcmp = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!vis[i][j] && g[i][j] == '1')
				{
					dfs(i,j);
					cntcmp++;
				}
			}
		}
		cout << "Image number " << tc++ << " contains " << cntcmp << " war eagles." << endl;
	}

}