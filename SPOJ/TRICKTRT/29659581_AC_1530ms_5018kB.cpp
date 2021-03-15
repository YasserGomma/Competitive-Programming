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
constexpr auto EPS = 1e-9;
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
int n;
vector<pair<double, double>>v;
void init()
{
    v.clear();
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
}
double f(double h) {
    double mx = -1e9;
    for (auto it : v)
    {
        double cal = hypot(it.first - h, it.second);
        mx = max(mx, cal);
    }
    return mx;

}

pair<double, double> ts() {
    double lo = -200000, hi = 200000;
    while (hi - lo > EPS) {
        double m1 = lo + (hi - lo) / 3, m2 = hi - (hi - lo) / 3;
        if (f(m1) > f(m2))
            lo = m1;
        else
            hi = m2;
    }
    return { lo , f(lo) };
}
int main()
{
 
    while (cin >> n && n)
    {
        init();
        pair<double, double>ans = ts();
        if (ans.first < EPS)
            ans.first = 0;
        cout << fixed << setprecision(6) << ans.first << " " << ans.second << endl;

    }
}