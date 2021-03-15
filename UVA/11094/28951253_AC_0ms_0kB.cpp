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
    //freopen("input.txt", "w", stdout);
#endif
}
int n, m;
char g[25][25];
int ans = 0, cnt = 0;
int vis[25][25];
char land;
void dfs(int i, int j)
{
    
    vis[i][j] = 1;
    cnt++;
    for (int id = 0; id < 4; id++)
    {
        int ni = dx[id] + i;
        int nj = dy[id] + j;
        if (nj < 0) nj = m - 1;
        if (nj >= m) nj = 0;
        if (ni >= 0 && ni < n) {
            if (!vis[ni][nj] && g[ni][nj] == land)
                dfs(ni, nj);
        }
        else return;
    }
}
void mark(int i, int j)
{

    vis[i][j] = 1;
    for (int id = 0; id < 4; id++)
    {
        int ni = dx[id] + i;
        int nj = dy[id] + j;
        if (nj < 0) nj = m - 1;
        if (nj >= m) nj = 0;
        if (ni >= 0 && ni < n) {
            if (!vis[ni][nj] && g[ni][nj] == land)
                dfs(ni, nj);
        }
        //else return;
    }
}
int main()
{
    COME_BACK();
    while (cin >> n >> m)
    {
      
        memset(vis, 0, sizeof vis);

        for (int i = 0; i < n; i++)cin >> g[i];
        int x, y;
        cin >> x >> y;
        land = g[x][y];
        mark(x, y);
        
       // cout << land << endl;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && g[i][j] == land)
                {
                   
                    cnt = 0;
                    dfs(i, j);
                  // cout << cnt << endl;
                    ans = max(ans, cnt);
                }
            }
        cout << ans << endl;
        ans = cnt = 0;
    }

}