/*(وَمَا تَوْفِيقِي إِلَّا بِاللَّه) */
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
#define all(v) ((v).begin()), ((v).end())	
#define sz(v) v.size()
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
constexpr auto EPS = 1e-7;
const int MOD = (int)1e9 + 7;
int dxn[] = { -1,-2,-2,-1,1,2,2,1 };
int dyn[] = { -2,-1,1,2,2,1,-1,-2 };
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
ll gcd(ll a, ll b) { return (a) ? gcd(b % a, a) : b; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
void COME_BACK()
{
    std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
}
bool isprime(ll n) {	
    if (n == 2)return true;
    if (n < 2 || n % 2 == 0)return false;
    for (ll i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}
bool can(int a, int b)
{
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        if (a % 10 != b % 10)cnt++;
        a /= 10, b /= 10;
    }
    return cnt <= 1;
}
int main()
{
    COME_BACK();
    vector<vector<int>>adj(100007);
    vector<int>pri;
    for (int i = 1000; i <= 9999; i++)
          if (isprime(i))pri.push_back(i);
    for(auto u:pri)
        for (auto v : pri)
        {
            if (can(u, v)) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        queue<pii>q;
        vector<int>dis(100007, INT_MAX);
        dis[a] = 0;
        q.push({ a,0 });
        while (!q.empty())
        {
            pii p = q.front();
            q.pop();
            for (auto ch : adj[p.first])
            {
                if (dis[ch] > p.second + 1)
                {
                    dis[ch] = p.second + 1;
                    q.push({ ch,dis[ch] });
                }
            }
        }
        if (dis[b] == INT_MAX) cout << "Impossible" << endl;
        else cout<<dis[b]<< endl;
    }
       
}