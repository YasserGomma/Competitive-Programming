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
int n;
char g[101][101];
int mem[101][101][11];
string ans = "ICPCASIASG";
bool ok(int i, int di, int j, int dj)
{
	return ((i - di) * (i - di) + (j - dj) * (j - dj)) == 5;
}
bool solve(int i, int j, int idx)
{
	if (idx == sz(ans))
		return 1;
	int &ret = mem[i][j][idx];
	if (~ret)
		return ret;
	ret = 0;
	for (int di = max(0, i - 5); di <= min(i + 5, n - 1) ; di++)
		for (int dj = max(0, j - 5); dj <= min(j + 5, n - 1) ; dj++)
		{
			if (ok(i, di, j, dj) && ans[idx] == g[di][dj])
				ret |= solve(di, dj, idx + 1);
			if (ret)
				return ret;
		}
	return ret;
}
int main()
{
	//nGu();
	clr(mem, -1);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> g[i][j];
	bool can = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (g[i][j] == 'I') {
				can |= solve(i, j, 1);
			}
			
		}
	if (!can)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;

}