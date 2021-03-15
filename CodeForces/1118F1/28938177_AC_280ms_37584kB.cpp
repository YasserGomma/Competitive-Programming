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
int dx[] = { -1 , -1 , -1 , 0 , 0 , 1 , 1 , 1 , 0 };
int dy[] = { -1 , 0 , 1 , -1 , 1 , -1 , 0 , 1 , 0 };
ll gcd(ll a, ll b) { return (a) ? gcd(b % a, a) : b; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
void COME_BACK()
{
    std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("input.txt", "w", stdout);
#endif
} vector<vector<int>>adj;
vector<int>clr, vis;
int red = 0, blue = 0, ans = 0;
pair<int, int>dfs(int node)
{
    vis[node] = 1;
    int curr = 0, curb = 0;
    if (clr[node] == 1)curr++;
    else if (clr[node] == 2)curb++;
    for (auto it : adj[node])
    {
        if (!vis[it]) {
            pair<int, int>p = dfs(it);
            if (p.first == red && !p.second) 
                ans++;
            if (!p.first && p.second == blue)
                ans++;
            curr += p.first;
            curb += p.second;
        }
    }
    return{ curr, curb };
}
int main()
{
    COME_BACK();
    int n; cin >> n;
    adj.resize(n + 1);
    clr.resize(n + 1);
    vis.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> clr[i];
        red += (clr[i] == 1);
        blue += (clr[i] == 2);
    }
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    cout << ans << endl;

}
