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
int n, m;
vector<vi>adj;

int main()
{
	COME_BACK();
	int t; cin >> t;
	int cnt = 1;
	while (t--)
	{
		cin >> n >> m;
		string src = string(n, '0');
		adj.clear();
		adj.resize(m);
		for (int i = 0; i < m; i++)
		{
			int u; cin >> u;
			while (u--)
			{
				int v; cin >> v;
				adj[i].push_back(v);
			}
		}
		queue<string>q;
		unordered_map<string, bool>vis;
		unordered_map<string, int>len;
		q.push(src);
		vis[src] = 1;
		len[src] = 0;
		while (!q.empty())
		{
			string node = q.front();
			q.pop();
			for (int i = 0; i < m; i++)
			{
				string ch = node;
				for (auto it : adj[i])
				{
					if (ch[it] == '1')ch[it] = '0';
					else ch[it] = '1';
				}
				if (vis.find(ch) == vis.end())
				{
					vis[ch] = 1;
					len[ch] = len[node] + 1;
					q.push(ch);
				}
			}
		}
		cout << "Case " << cnt++ << ":" << endl;
		int qu; cin >> qu;
		while (qu--)
		{
			string s; cin >> s;
			reverse(all(s));
			if (vis.find(s) == vis.end())
				cout << -1 << endl;
			else cout << len[s] << endl;
		}
		cout << endl;

	}

}
