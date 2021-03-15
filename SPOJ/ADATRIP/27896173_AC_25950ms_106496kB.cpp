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
    //freopen("out.txt", "w", stdout);
#endif
}
struct edge {
    ll from, to, w;
    edge(ll from, ll to, ll w) :from(from), to(to), w(w) {}
    bool operator < (const edge& e)const {
        return (w > e.w);
    }
};

int n,m,q;
vector<vector<edge>>adj;
vector<ll>cost;
void dijkstra(int startNode) {
    priority_queue<edge>q;
    q.push({ -1,startNode,0 });
   // cost = vector<ll>(n + 1, 1e18);
    cost[startNode] = 0;
    while (!q.empty()) {
        edge par = q.top();
        q.pop();
        if (par.w > cost[par.to])continue;

        for (auto ch : adj[par.to]) {
            if (par.w + ch.w < cost[ch.to]) {
                cost[ch.to] = par.w + ch.w;
                q.push({ ch.from,ch.to,par.w + ch.w});
            }
        }
    }
    
}
int main()
{
    COME_BACK();
    cin >> n >> m>> q;
    adj.resize(n+1);
    cost = vector<ll>(n + 1, 1e18);
    for (int i = 0; i < m; i++)
    {
        int from, to, w;
        cin >> from >> to >> w;
        adj[from].push_back({from,to,w });
        adj[to].push_back({ to,from,w });
    }
    while (q--)
    {
        int scr;
        cin >> scr;
        dijkstra(scr);
        ll mn =0,cnt=0;
        for (int i = 0; i < n; i++)
            if (cost[i] != 1e18 && mn < cost[i])mn = cost[i], cnt = 1;
            else if(cost[i]== mn) cnt++;
        cout << mn << " " <<cnt<< endl;
        cost = vector<ll>(n + 1, 1e18);
    }


}
