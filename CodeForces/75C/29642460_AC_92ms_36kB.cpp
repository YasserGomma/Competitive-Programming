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
vector<int>di;
void fact(int n)
{
	for (int i = 1; i <= n / i; ++i)
	{
		if (n % i == 0)
		{
			di.push_back(i);
			if (i != n / i)
				di.push_back(n / i);

		}
	}
	sort(all(di));
	reverse(all(di));
}
int main()
{
 nGu();
	int a, b;
	cin >> a >> b;
	fact(gcd(a, b));
	int q;
	cin >> q;
	while (q--)
	{
		int ans = -1;
		int l, h;
		cin >> l >> h;
		for(auto it:di)
			if (it >= l && it <= h)
			{
				ans = it;
				break;
			}
		cout << ans << endl;
	}
}