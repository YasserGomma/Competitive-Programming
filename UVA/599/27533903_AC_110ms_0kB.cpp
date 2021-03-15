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
vector<vi>adj;
vector<int>vis;
bool isCycle(int u, int parent) {
    vis[u] = true;
    for (auto ch : adj[u]) {

        if (!vis[ch]) {
            if (isCycle(ch, u)) return true;

        }
        else if (ch != parent) return true;
    }
    return false;
}
int main()
{
    COME_BACK();
    int t; cin >> t; while (t--) {
        string s;
        adj.resize(30), vis.resize(30);
        while (cin >> s)
        {
            if (s[0] == '*')
            {
                string nodes; cin >> nodes;
                int tr = 0, ar = 0;
                for (int i = 0; i < sz(nodes); i += 2)
                {
                    if (!sz(adj[nodes[i] - 'A']))ar++;
                }
                for (int i = 0; i < 26; i++)
                {
                    if (sz(adj[i]) && !vis[i])
                    {
                        if (!isCycle(i, -1))tr++;
                    }
                }
                cout << "There are " << tr << " tree(s) and " << ar << " acorn(s)." << endl;
                vis.clear();
                adj.clear();
                adj.resize(30), vis.resize(30);
                continue;

            }
            int u = s[1] - 'A', v = s[3] - 'A';
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

}