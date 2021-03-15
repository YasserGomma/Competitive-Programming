#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
#define deb(x)   cout << "[" <<#x << "=" << x << "]" << endl
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
constexpr auto EPS = 1e-7;
const int mod = (int)1e9 + 7;
#define clr(v, d)		memset(v, d, sizeof(v))
int dxn[] = { -1,-2,-2,-1,1,2,2,1 };
int dyn[] = { -2,-1,1,2,2,1,-1,-2 };
int dx[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
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

int main()
{
	//nGu();
	int n, h;
	cin >> n >> h;
	vector<int>v(n);
	vector<int>level(h + 2, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		if (i & 1)
		{
			int len = h - v[i] + 1;
			level[len]++;
			level[h + 1]--;
		}
		else
		{
			level[1]++;
			level[v[i] + 1]--;
		}
	}
	for (int i = 1; i <= h; i++)
		level[i] += level[i - 1];
	map<int, int>cnt;
	for (int i = 1; i <= h; i++)
		cnt[level[i]]++;
	pii ans = *cnt.begin();
	cout << ans.first << " " << ans.second << endl;

}