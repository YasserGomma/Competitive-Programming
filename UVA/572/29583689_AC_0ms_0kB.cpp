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
int n, m;
char g[101][101];
bool vis[101][101];
void init()
{
    memset(vis, 0, sizeof vis);
}
bool valid(int i, int j)
{
    return i >= 0 && i < n&& j >= 0 && j < m&& g[i][j] == '@';
}
void dfs(int i, int j)
{
    vis[i][j] = 1;
    for (int id = 0; id < 8; id++)
    {
        int ni = i + dx[id], nj = j + dy[id];
        if (valid(ni, nj) && !vis[ni][nj])
            dfs(ni, nj);
    }
}
int main()
{
    nGu();
    while (cin >> n >> m)
    {
        if (!n)break;

        init();
        for (int i = 0; i < n; i++)
            for(int j=0;j<m;j++)
            cin >> g[i][j];
        int cnt = 0;
        for(int i=0;i<n;i++)
            for (int j = 0; j < m; j++)
            {
                if (g[i][j] == '@' && !vis[i][j])
                {
                    cnt++;
                    dfs(i, j);
                }
            }
        cout << cnt << endl;
    }
}
