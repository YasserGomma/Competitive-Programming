#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>	
using namespace std;
typedef long long ll;
#define bay_bay return 0;
#define fori(n) for(int i=0;i<n;++i)
#define for1(n) for(int i=1;i<=n;i+=3)
#define all(v) ((v).begin()), ((v).end())	
#define sz(v) v.size()
#define endl "\n"
constexpr auto EPS = 1e-9;
#define ff fflush(stdout);
const int mod = 1000000007;
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
void GOAT()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
#endif
}
int n, m;
int vis[100009], len[100009];
vector<vector<int>>adj;
void dfs(int node)
{
    vis[node] = 1;
    len[node] = 0;
    for (auto& child : adj[node])
    {
        if (!vis[child])
            dfs(child);
        len[node] = max(len[node], len[child] + 1);
    }
}
int main()
{
	//GOAT();
    memset(vis, 0, sizeof vis);
    memset(len, 0, sizeof len);
    cin >> n >> m;
    adj=vector<vector<int>>(n+1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u>>v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    int mx = 0;
    for (int i = 1; i <= n; i++)mx = max(mx, len[i]);
    cout << mx << endl;
}