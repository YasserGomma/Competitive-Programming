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
vector<int>nxt, v;
int n, t;
string x;
void init()
{
   
    v.clear();
    v.resize(n);
}
void init1()
{
    nxt.clear();
    nxt.resize(sz(x) + 1, -1);
}
int cut(int pos)
{
    int s = pos, e;
    while (!~nxt[s]) s--;
    
    e = nxt[s];
    nxt[pos + 1] = e;
    nxt[s] = pos;
    set<char>s1, s2;
    for (int i = s; i <= pos; i++)
        s1.insert(x[i]);
    for (int i = pos + 1; i <= e; i++)
        s2.insert(x[i]);
    int cnt = 0;
    for (auto it : s1) {
        if (s2.find(it) == s2.end())
            cnt++;
    }
    for (auto it : s2) {
        if (s1.find(it) == s1.end())
            cnt++;
    }
    return cnt;
}
int main()
{
    nGu();

    cin >> t;
    while (t--)
    {

        cin >> n;
        init();
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            v[i]--;
        }
        cin >> x;
        init1();
        nxt[0] = sz(x) - 1;
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += cut(v[i]);
        cout << ans << endl;

    }


}