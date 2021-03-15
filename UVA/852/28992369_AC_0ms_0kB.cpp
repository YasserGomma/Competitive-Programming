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
void ReturnNEWBIE()
{
    std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
}
char grid[10][10];
bool vis[10][10];
bool valid(int i, int j)
{
    return(i >= 0 && j >= 0 && i < 9 && j < 9);
}
int dfs(int i, int j)
{
    vis[i][j] = 1;
    if (grid[i][j] == 'O')return 1;
    if (grid[i][j] == 'X')return 2;
    //if (vis[i][j])return 0;
    int flag = 0;
    for (int idx = 0; idx < 4; idx++)
    {
        int ni = i + dx[idx], nj = j + dy[idx];
        if (valid(ni, nj)&&!vis[ni][nj])
            flag |= dfs(ni, nj);
    }
    return flag;

}
int main()
{
    ReturnNEWBIE();
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 9; i++)cin >> grid[i];
        int b = 0, w = 0;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (grid[i][j] == 'X')b++;
                else if (grid[i][j] == 'O')w++;
                else
                {
                    memset(vis, 0, sizeof vis);
                    int ans=dfs(i, j);
                    if (ans == 1)w++;
                    else if (ans == 2)b++;
                }
                //cout << grid[i][j];
            }
        }
        cout << "Black " << b << " White " << w << endl;

    }
}