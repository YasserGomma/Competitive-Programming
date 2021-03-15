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
char grid[10][10];
bool vis[10][10];
bool valid(int i, int j)
{
    return(i >= 0 && j >= 0 && i < 9 && j < 9);
}
int dfs(int i, int j)
{
    vis[i][j] = 1;
    if (grid[i][j] == 'O')return 1;
    if (grid[i][j] == 'X')return 2;
    //if (vis[i][j])return 0;
    int flag = 0;
    for (int idx = 0; idx < 4; idx++)
    {
        int ni = i + dx[idx], nj = j + dy[idx];
        if (valid(ni, nj)&&!vis[ni][nj])
            flag |= dfs(ni, nj);
    }
    return flag;

}
int main()
{
    ReturnNEWBIE();
    int n;
    while (cin >> n && n)
    {
        map<string, string>mp;
        vector<string>v(n);
        for (int i = 0; i < n; i++)
        {
            string a, b;
            cin >> a >> b;
            v[i] = a;
            mp[a] = b;
        }
        string src, dis;
        cin >> src >> dis;
        queue<pair<string, int>>q;
        map<string, int>vis;
        q.push({ src,0 });
        int ans = -1;
     
        while (sz(q))
        {
            pair<string, int>p = q.front();
            if (p.first == dis)
            {
                ans = p.second;
                break;
            }
            q.pop();
            string cur = p.first;
            int dep = p.second;
           // cout << cur << endl;
            if (sz(cur) >= sz(dis))continue;
            for (int i = 0; i < n; i++)
            {
                string t = "";
                for (int j = 0; j < sz(cur); j++)
                {
                    string sub = cur.substr(j, (int)sz(v[i]));
                    if (sub == v[i])
                    {
                        t += mp[v[i]];
                        j += sz(v[i]) - 1;
                    }
                    else
                        t += cur[j];
                   
                }
                //cout << cur << " " << t << endl;
                if (!vis.count(t))
                {
                    vis[t] = 1;
                    q.push({t, dep + 1});
                }
               

            }

        }
        cout << ans << endl;

    }
}