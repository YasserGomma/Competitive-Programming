#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
#define deb(x)   cout << "[" <<#x << "=" << x << "]" << endl
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
constexpr auto EPS = 1e-7;
int mod = (int)1e9 + 7;
#define clr(v, d)		memset(v, d, sizeof(v))
int dxn[] = { -1,-2,-2,-1,1,2,2,1 };
int dyn[] = { -2,-1,1,2,2,1,-1,-2 };
int dx[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
ll gcd(ll a, ll b)
{
    return (a) ? gcd(b % a, a) : b;
}
ll lcm(ll a, ll b)
{
    return (a * b) / gcd(a, b);
}
void nGu()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
}
const int MAX = 2e5 + 5;
int indeg[MAX], outdeg[MAX], n, m, start;
vector<vector<int>>adj(MAX);
vector<int>res;
void init()
{
    clr(indeg, 0);
    clr(outdeg, 0);
    for (int i = 0; i < n; i++)
        adj[i].clear();
    res.clear();
    start = 0;
}
void  countInOutdeg()
{
    for (int i = 0; i < n; i++)
        for (auto to : adj[i])
            indeg[to]++, outdeg[i]++;
}
bool EulerPath()
{
    int first = 0, last = 0;
    for (int i = 0; i < n; i++)
    {
        if (abs(indeg[i] - outdeg[i]) > 1)
            return 0;
        if (outdeg[i] - indeg[i] == 1)
            first++;
        if (indeg[i] - outdeg[i] == 1)
            last++;
        if (indeg[i] - outdeg[i] == -1)
            start = i;
    }

    return  ((first == 1 && last == 1) || (!first && !last));

}
void dfs(int u)
{
    while (outdeg[u])
        dfs(adj[u][--outdeg[u]]);
    res.push_back(u);

}
bool Hierholzer()
{
    countInOutdeg();

    if (!EulerPath()) return 0;
    dfs(start);
    reverse(all(res));
    return sz(res)==m+1;
}
int main()
{

    while (cin >> n >> m && (n + m))
    {
        init();
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        if (!Hierholzer())
            cout << "Impossible";
        else
            for (auto it : res)
                cout << it << " ";
        cout << endl;
    }

}
