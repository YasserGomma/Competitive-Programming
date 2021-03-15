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
    // freopen("out.txt", "w", stdout);
#endif
}
bool vis[200009];
void dfs(int node, vector<vi>& adj)
{
    vis[node] = 1;
    cout << node << " ";
    for (auto it : adj[node])
        if (!vis[it])
            dfs(it, adj);
}
int main()
{
    COME_BACK();
    int n;
    cin >> n;
    vector<set<int>>dir(n + 1), line(n + 1);
    vector<vi>adj(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        dir[i].insert(v);
        dir[i].insert(u);
        line[u].insert(v);
        line[v].insert(u);
    }
    for (int i = 1; i <= n; i++)
        for (auto it : dir[i])
            if (line[i].count(it))
                adj[i].push_back(it);
    dfs(1, adj);
}