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
#define clr(v, d)		memset(v, d, sizeof(v))
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
vector<pii>item;
int k, m;
int mem[51][1001];
int solve(int i, int rem)
{
	if (i == m)
		return 0;

	int &ret = mem[i][rem];
	if (~ret)
		return ret;
	ret = 0;
	ret = solve(i + 1, rem);
	if (rem >= item[i].first)
		ret =max(ret, solve(i + 1, rem - item[i].first) + item[i].second);
	return ret;
}
int main()
{
	//nGu();
	int t;cin >> t;
	while (t--)
	{
		cin >> k >> m;
		item.clear();
		item.resize(m);
		clr(mem, -1);
		for (int i = 0; i < m; i++)
	      	cin >> item[i].first >> item[i].second;

		cout << "Hey stupid robber, you can get " << solve(0, k) << "." << endl;
	}
}
