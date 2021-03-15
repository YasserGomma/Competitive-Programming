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
int vis[20][20],vid,n,m,c,ei,ej;
bool cycle = 0;
char g[20][20];
map<char, pii>dir;
bool valid(int i, int j)
{
    return  i >= 0 && i < n&& j >= 0 && j < m;
}
int dfs(int i, int j)
{
    vis[i][j] = vid;
    int ni = i + dir[g[i][j]].first, nj = j + dir[g[i][j]].second;
    if (!valid(ni, nj))
    {
        return 0;
    }
    if (vis[ni][nj] == vid)
    {
        ei = ni;
        ej = nj;
        cycle = 1;
        return 0;
    }
    return 1 + dfs(ni, nj);
}
void init()
{
    dir['N'] = { -1,0 };
    dir['S'] = { 1,0 };
    dir['W'] = { 0,-1 };
    dir['E'] = { 0,1 };
}
int main()
{
    nGu();
    init();
    while (cin >> n >> m >> c && n && m && c)
    {
        ++vid;
        cycle = 0;
        for (int i = 0; i < n; i++)
            cin >> g[i];
        int ans = 1+dfs(0, c - 1);
        if (!cycle)
            cout << ans << " step(s) to exit" << endl;
        else
        {
            ++vid;
            int cy = 1+dfs(ei, ej);
            cout << ans - cy << " step(s) before a loop of "<< cy << " step(s)" << endl;
        }
    }

    
}