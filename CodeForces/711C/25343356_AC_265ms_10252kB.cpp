#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>	
using namespace std;
typedef long long ll;
#define bay_bay return 0;
#define fori(n) for(int i=0;i<n;++i)
#define all(v) ((v).begin()), ((v).end())	
#define sz(v) v.size()
#define endl "\n"
constexpr auto EPS = 1e-9;
#define oo ll(1e18)
#define ff fflush(stdout);
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
void GOAT()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

}
int n, m, k;
ll c[109], co[109][109], mem[109][109][109];
ll solve(int idx, int pre, int rem)
{
    if (rem < 0)return oo;
    if (idx == n)return rem>0 ? oo : 0;
    ll& ret = mem[idx][pre][rem];
    if (~ret)return ret;
    ret = oo;
    if (c[idx])
    {
        if (pre != c[idx])
            ret = min(ret, solve(idx + 1, c[idx], rem - 1));
        else
            ret = min(ret, solve(idx + 1, c[idx], rem));
    }
    else
    {
        for (int i = 1; i <= m; i++)
        {
            if (pre != i)
                ret = min(ret, solve(idx + 1, i, rem - 1) + co[idx][i]);
            else
                ret = min(ret, solve(idx + 1, i, rem) + co[idx][i]);
        }
    }
    return ret;
}


int main()
{
    GOAT();
    memset(mem, -1, sizeof mem);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)cin >> c[i];
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= m; j++)
            cin >> co[i][j];
    ll ans = solve(0, 0, k);
    if (ans >= oo) cout << -1 << endl;
    else cout << ans << endl;



}
