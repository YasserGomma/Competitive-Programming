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
int n;
vector<vector<int>>adj;
vector<int>vis;
void dfs(int u)
{

    for (auto it : adj[u])
    {
        if (!vis[it])
        {
            vis[it] = 1;
            dfs(it);
        }
    }
}
void init()
{
    adj.clear();
    adj.resize(n + 1);
}
int main()
{
    nGu();
    while (cin >> n && n)
    {
        init();
        int u;
        while (cin >> u && u)
        {
            int v;
            while (cin >> v && v)
            {
                adj[u].push_back(v);
            }
        }
        /* for (int i = 1; i <= n; i++)
         {
             cout << i << "-----";
             for (auto it : adj[i])
                 cout << it << " ";
             cout << endl;
         }*/
        int q;
        cin >> q;
        while (q--)
        {
            int src;
            cin >> src;
            vis.clear();
            vis.resize(n + 1);
            dfs(src);
            vector<int>bad;
            for (int i = 1; i <= n; i++)
                if (!vis[i])
                    bad.push_back(i);
            cout << sz(bad);
            for (auto it : bad)
                cout <<" "<< it;
            cout << endl;
        }
        // cout << n << " " << endl;
    }

}