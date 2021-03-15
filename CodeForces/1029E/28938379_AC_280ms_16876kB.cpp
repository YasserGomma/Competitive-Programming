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
} vector<vector<int>>adj;
vector<int>dis, par, vis, par_update;

int main()
{
    COME_BACK();
    int n; cin >> n;
    adj.resize(n + 1);
    vis.resize(n + 1, 0);
    par.resize(n + 1);
    dis.resize(n + 1, INT_MAX);
    par_update.resize(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
      adj[v].pb(u);
    }
    queue<int>q;
    q.push(1);
    dis[1] = 0;
    par[1] = -1;
    while (sz(q))
    {
        int pr = q.front();
        q.pop();
        for (auto ch : adj[pr])
        {
            if (dis[ch] == INT_MAX)
            {
                q.push(ch);
                par[ch] = pr;
                dis[ch] = dis[pr] + 1;

            }
        }
    }
    set<pair<int, int>> st;
    for (int i = 1; i <= n; ++i) {
        if (dis[i] > 2) {
            st.insert(make_pair(-dis[i], i));
        }
    }
    int ans = 0;
    while (!st.empty()) {
        int v = st.begin()->second;
        v = par[v];
        ++ans;
        auto it = st.find(make_pair(-dis[v], v));
        if (it != st.end()) {
            st.erase(it);
        }
        for (auto to : adj[v]) {
            auto it = st.find(make_pair(-dis[to], to));
            if (it != st.end()) {
                st.erase(it);
            }
        }
    }
    cout << ans << endl;
}