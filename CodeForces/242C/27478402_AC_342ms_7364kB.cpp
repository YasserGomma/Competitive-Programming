#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>	
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
#define all(v) ((v).begin()), ((v).end())	
#define sz(v) v.size()
#define endl "\n"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
constexpr auto EPS = 1e-9;
const int mod = (int)1e9 + 7;
const double pi = acos(-1);
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
ll gcd(ll a, ll b) { return (a) ? gcd(b % a, a) : b; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
void GOAT()
{
	std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);// freopen("out.txt", "w", stdout);
#endif
}
pii sc, dis;
map<pii, bool>allowed;
map<pii, int>cost;
int bfs(pii src, pii dist)
{
	cost[src] = 0;
	queue<pii>q;
	q.push(src);
	while (!q.empty())
	{
		
		pii node = q.front();
		q.pop();
		if (node == dist)return cost[node];
		for (int i = 0; i < 8; i++)
		{
			pii child = { node.first + dx[i],  node.second + dy[i]};
			if (allowed.find(child) == allowed.end())continue;
				if (cost.find(child) == cost.end()) {
					cost[child] = cost[node] + 1,q.push(child);
				}
		}
	}
	return -1;
}

int main()
{
	GOAT();
	int x0, x1, y0, y1;
	cin >> x0 >>y0 >> x1 >> y1;
	int t; cin >> t;
	while (t--)
	{
		int r, a, b;
		cin >> r >> a >> b;
		for (int i = a; i <= b; i++)
			allowed[make_pair(r,i)]=1;
	}
	sc = make_pair(x0, y0), dis = make_pair(x1, y1);
	int ans = bfs(sc, dis);
	cout <<ans<< endl;
}