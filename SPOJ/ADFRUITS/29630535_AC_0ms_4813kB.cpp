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
string s, t;
string ans = "";
int mem[109][109];
int lcs(int i, int j)
{
	if (i == sz(s) || j == sz(t))
		return 0;
	int &ret = mem[i][j];
	if (~ret)
		return ret;
	if (s[i] == t[j])
	{
		return ret = 1+lcs(i + 1, j + 1);
	}
	return ret = max(lcs(i, j + 1), lcs(i + 1, j));
}
void build(int i, int j)
{
	if (i == sz(s)||j == sz(t))
		return;
	if (s[i] == t[j])
	{
		ans += s[i];
		build(i + 1, j + 1);
		return;
	}
	int ch1 = lcs(i + 1, j), ch2 = lcs(i, j + 1);
	if (ch1>ch2) 
		build(i + 1, j);
	else 
		build(i, j + 1);
}
int main()
{
	//nGu();
	while (cin >> s >> t) {
		clr(mem, -1);
		lcs(0, 0);
		build(0, 0);
		//cout << ans << endl;
		int i = 0, j = 0;
		for (auto it : ans)
		{
			while (i < sz(s) && s[i] != it)
				cout << s[i++];
			while (j < sz(t) && t[j] != it)
				cout << t[j++];
			cout << it;
			i++, j++;
		}
		while (i < sz(s))
			cout << s[i++];
		while (j < sz(t))
			cout << t[j++];
		cout << endl;
		ans = "";
	}
	
}