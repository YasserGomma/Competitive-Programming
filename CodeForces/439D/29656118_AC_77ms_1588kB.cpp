#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
#define deb(x)   cout << "[" <<#x << "=" << x << "]" << endl
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
constexpr auto EPS = 1e-7;
const int mod = (int)1e9 + 7;
#define clr(v, d)		memset(v, d, sizeof(v))
int dxn[] = { -1,-2,-2,-1,1,2,2,1 };
int dyn[] = { -2,-1,1,2,2,1,-1,-2 };
int dx[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
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
vector<ll>v, c;
void init()
{
    cin >> n>>m;
    v.clear();
    c.clear();
    v.resize(n);
    c.resize(m);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < m; i++)
        cin >> c[i];
}
ll f(ll mn)
{
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(v[i] < mn)
        ans += abs(mn - v[i]);
    }
    for (int i = 0; i < m; i++)
    {
        if (c[i] > mn)
            ans += abs(mn - c[i]);
    }
    return ans;
}
ll ts()
{
    ll st = 1, end = 2e9, m1 = -1, m2 = 0;
    while (st <= end)
    {
        m1 = st + (end - st) / 3;
        m2 = end - (end - st) / 3;
        if (f(m1) >= f(m2))
            st = m1+1 ;
        else
            end = m2-1 ;
    // cout<<st<<" "<<end<<" "<<m1<<" "<<m2<<endl;
    }
    return min({ f(st),f(m1),f(m2),f(end) });
}
int main()
{
    nGu();
    int t = 1;
    while (t--)
    {
        init();
        cout << ts() << endl;
    }


}