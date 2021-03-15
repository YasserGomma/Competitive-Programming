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
char g[55][55];
bool vis[55][55];
bool ok(int i, int j)
{
    return (g[i][j] != '#' &&i >= 0 && j >= 0 && i < n&& j < m);
}
void bfs(int i, int j)
{
    queue<pii>q;
    q.push({ i,j });
    while (sz(q))
    {
        pii p = q.front();
        q.pop();
        if (p.first < n - 1 && g[p.first + 1][p.second] == '.')
        {
            g[p.first + 1][p.second] = 'V';
            vis[p.first + 1][p.second] = 1;
            q.push({ p.first + 1,p.second });

        }
        else if (p.first < n - 1 && g[p.first + 1][p.second] == '#')
        {
            i = p.first, j = p.second + 1;
            if (ok(i, j) && !vis[i][j])
            {
                g[i][j] = 'V';
                vis[i][j] = 1;
                q.push({ i,j });
               
            }
            j -= 2;;
            if (ok(i, j) && !vis[i][j])
            {
                g[i][j] = 'V';
                vis[i][j] = 1;
                q.push({ i,j });
               
            }
        }
    }
}
int main()
{
   // nGu();
    cin >> n >> m;
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> g[i][j];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && g[i][j] == 'V')
                bfs(i, j);
        }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << g[i][j];
        cout << endl;
    }

}
