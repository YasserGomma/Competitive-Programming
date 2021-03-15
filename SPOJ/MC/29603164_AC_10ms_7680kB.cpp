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
#define clr(v, d)		memset(v, d, sizeof(v))
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
string s, t;
int mem[1009][1009];
int LCS(int i, int j)
{
    if (i == sz(s) || j == sz(t))
        return 0;
    int& ret = mem[i][j];
    if (~ret)return ret;
    if (s[i] == t[j])
        return ret = 1 + LCS(i + 1, j + 1);
    int ch1 = LCS(i + 1, j);
    int ch2 = LCS(i, j + 1);
    return ret = max(ch1, ch2);
	
}
int main()
{
 //   nGu();
    while (cin >> s && s != "#")
    {
        cin >> t;
        clr(mem, -1);
        int ans= LCS(0,0) ;
        cout << 15 * (sz(s) - ans) + 30 * (sz(t) - ans) << endl;

    }
	
}