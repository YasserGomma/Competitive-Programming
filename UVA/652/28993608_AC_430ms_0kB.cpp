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
string up(string s)
{
    int idx = s.find('x');
    if (idx < 3)return s;
    swap(s[idx], s[idx - 3]);
    return s;

}
string down(string s)
{
    int idx = s.find('x');
    if (idx > 5)return s;
    swap(s[idx], s[idx + 3]);
    return s;

}
string left(string s)
{
    int idx = s.find('x');
    if (idx % 3 == 0)return s;
    swap(s[idx], s[idx - 1]);
    return s;

}
string right(string s)
{
    int idx = s.find('x');
    if (idx % 3 == 2)return s;
    swap(s[idx], s[idx + 1]);
    return s;

}
int main()
{
    ReturnNEWBIE();
    string src = "12345678x";
    queue<pair<string, string>>q;
    map<string, string>vis;
    q.push({ src,"" });
    vis[src] = "";
    while (sz(q))
    {
        string p = q.front().first;
        string dep = q.front().second;
        q.pop();

        string u = up(p), d = down(p), l = left(p), r = right(p);
        if (!vis.count(u)) {
            vis[u] = 'd'+dep ;
            q.push({ u,vis[u] });
        }
        if (!vis.count(d)) {
            vis[d] = 'u' + dep;
            q.push({ d,vis[d] });
        }
        if (!vis.count(l)) {
            vis[l] = 'r'+dep ;
            q.push({ l,vis[l] });
        }
        if (!vis.count(r))
        {
            vis[r] = 'l'+dep ;
            q.push({ r,vis[r] });
        }

    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string dis = "";
        for (int j = 0; j < 9; j++)
        {
            char c; cin >> c;
            dis += c;
        }
        if (i)cout << endl;
        if (vis.count(dis))cout << vis[dis] << endl;
        else cout << "unsolvable" << endl;
    }

}