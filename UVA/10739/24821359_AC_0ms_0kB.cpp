#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define all(v)			((v).begin()), ((v).end())
#define sz(v)			((int)((v).size()))
#define clr(v, d)		memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
typedef long long         ll;
const double EPS = (1e-7);
int dcmp(double x, double y)
{
    return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}
#define pb					push_back
#define P(x)				cout<<#x<<" = { "<<x<<" }\n"
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
void GOAT()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("output.txt", "w	", stdout);
#else
#endif

}

int mem[1009][1009];
string s    ;
ll solve(int i, int j)
{
    int &ret = mem[i][j];
    if (ret != 2e9)return ret;
    if (j <= i) return ret = 0;
    if (s[i] == s[j])return ret = solve(i + 1, j - 1);
        int ch1 = solve(i + 1, j - 1);
        int ch2 = solve(i + 1, j);
        int ch3 = solve(i, j - 1);
        return ret = 1 + min({ ch1,ch2,ch3 });
}

int main()
{
   // GOAT();
    int t;
    cin >> t;
    for (int cnt = 1; cnt <= t; cnt++)
    {
        cin >> s;
        for (int i = 0; i <= sz(s); i++)
            for (int j = 0; j <= sz(s); j++)
                mem[i][j] = 2e9;
        cout << "Case " << cnt << ": ";
        cout << solve(0,sz(s)-1) << endl;
    }


}
