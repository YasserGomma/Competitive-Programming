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
#define oo 0x3F3F3F3F
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
int n, s, k;
int mem[51][2009], r[51];
string c;
int solve(int idx, int rem, int lastc, int lastr)
{
    if (rem <= 0)return 0;
    int& ret = mem[idx][rem];
    if (~ret)return ret;
    ret = oo;
    for (int i = 0; i < n; i++)
    {
        if (c[i] != lastc && r[i] > lastr)
            ret = min(ret, solve(i, rem - r[i], c[i], r[i]) + abs(idx - i));
    }
    return ret;

}

int main()
{
    GOAT();
    cin >> n >> s >> k;
    for (int i = 0; i < n; i++)cin >> r[i];
    cin >> c;
    int ans = oo;
    memset(mem,-1, sizeof mem);
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, solve(i, k - r[i], c[i], r[i]) + abs(s- i-1));
    }
    if (ans != oo)cout << ans << endl;
    else cout << -1 << endl;
    

}