#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
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
int n, m, q;
vector<vector<pii>>adj(109);
vector<int>vis(109);
bool dfs(int u, int col, int v)
{
    vis[u] = 1;
    if (u == v)return 1;
    for (auto it : adj[u])
    {
        if (it.second == col && !vis[it.first])
            if(dfs(it.first, col, v))
                return 1;
    }
    return 0;
}
int main()
{
	nGu();
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({ v,c });
        adj[v].push_back({ u,c });
    }

    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        int ans = 0;
       
           
            for (int i = 1; i <= 100; i++)
            {
                vis.clear();
                vis.resize(105);
                if (dfs(u, i, v))
                    ans++;
            }
        cout << ans << endl;
    }
	
}
