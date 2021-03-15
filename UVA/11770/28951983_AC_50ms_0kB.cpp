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
void COME_BACK()
{
    std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
     freopen("out.txt", "w", stdout);
#endif
}
int n, m, t;
vi vis, topo;
vector<vi>adj;
void dfs(int node)
{
    vis[node] = 1;
    for (auto child : adj[node])
    {
        if (!vis[child])
            dfs(child);
    }
    topo.push_back(node);

}
void form(int n)
{
    adj.clear();
    adj.resize(n + 1);
    vis.clear();
    vis.resize(n + 1);
    topo.clear();
}
int main()
{
    COME_BACK();
    cin >> t;
    for (int id = 1; id <= t; id++)
    {

        cin >> n >> m;
        form(n);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (!vis[i])
                dfs(i);

        vis.clear();
        vis.resize(n + 1);
        reverse(all(topo));
      for(int i=0;i<n;i++)
          if (!vis[topo[i]])
          {
              dfs(topo[i]);
              ans++;
          }
        cout << "Case " << id << ": " << ans << endl;
    }

}