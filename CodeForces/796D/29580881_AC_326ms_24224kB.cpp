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

int main()
{
    nGu();
    int n, k, d;
    cin >> n >> k >> d;
    queue<pair<int, int>>q;
    for (int i = 0; i < k; i++)
    {
        int u; cin >> u;
        q.push({ u,0 });
    }
    vector<vector<pair<int, int>>>adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({ v,i + 1 });
        adj[v].push_back({ u,i + 1 });
    }
    vector<int>vis(n + 1, 0),del(n+1,0);
    while (sz(q))
    {
        auto p = q.front();
        q.pop();
        if (vis[p.first])
            continue;
        vis[p.first] = 1;
        for (auto it : adj[p.first])
        {
            auto u = it;
            if (u.first != p.second) {
                if (vis[u.first])del[u.second] = 1;
                else
                    q.push({ u.first,p.first });
            }

        }
    }
    int ans = 0;
    for (int i = 1; i <n; i++) 
        if (del[i]) ans++;
    cout << ans << endl;
    for (int i = 1; i < n; i++)
        if (del[i])
            cout << i << " ";

}
