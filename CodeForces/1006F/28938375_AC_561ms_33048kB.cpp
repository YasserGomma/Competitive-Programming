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
}
int n, m, mid;
bool valid(int i, int j)
{
    return i >= 0 && j >= 0 && i < n&& j < m;
}
ll g[25][25];
map<ll, int>cnt[25][25];
ll ans = 0,k;
void dfs_scr(int i, int j, int steps, ll cur)
{
    cur ^= g[i][j];
    if (steps == mid)
    {
        cnt[i][j][cur]++;
        return;
    }
    if (valid(i + 1, j))
        dfs_scr(i + 1, j, steps + 1, cur);
    if(valid(i,j+1))
        dfs_scr(i , j+1, steps + 1, cur);

}
void dfs_dis(int i, int j, int steps, ll cur)
{
    if (steps == n+m-2-mid)
    {
        if (cnt[i][j].count(k ^ cur))
            ans += cnt[i][j][k ^ cur];
        return;
    }
    cur ^= g[i][j];
    if (valid(i - 1, j))
        dfs_dis(i - 1, j, steps + 1, cur);
    if (valid(i, j - 1))
        dfs_dis(i, j - 1, steps + 1, cur);

}
int main()
{
    COME_BACK();
    cin >> n >> m >> k;
    /*max steps n+m-2
    ts O(pow(2,n+m-2))-> TLE
    MIM O(pow(2,(n+m-2)/2))->AC
    */
    mid = (n + m - 2)>>1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];
    dfs_scr(0, 0, 0, 0);
    dfs_dis(n - 1, m - 1, 0, 0);
    cout << ans << endl;

}
