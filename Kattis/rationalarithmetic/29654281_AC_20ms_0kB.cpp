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
pair<ll, ll>fix(ll n, ll d)
{
	if (n < 0 && d < 0)
		return { -n,-d };
	else if (d < 0)
		return { -n,-d };
	return { n,d };
}
int main()
{
	
	int n;
	cin >> n;
	while (n--)
	{
		ll x1, y1, x2, y2;
		char op;
		cin >> x1 >> y1>>op >> x2 >> y2;
		if (op == '*')
		{
			ll N = x1 * x2 ;
			ll D = y1 * y2;
			ll gc = gcd(abs(N), abs(D));
			D /= gc;
			N /= gc;
			pair<ll, ll>ans = fix(N, D);
			cout << ans.first << " / " << ans.second << endl;
		}
		else if (op == '+')
		{
			ll N = x1 * y2 + x2 * y1;
			ll D = y1 * y2;
			ll gc = gcd(abs(N), abs(D));
			D /= gc;
			N /= gc;
			pair<ll, ll>ans = fix(N, D);
			cout << ans.first << " / " << ans.second << endl;
		}
		else if (op == '-')
		{
			ll N = x1 * y2 - x2 * y1;
			ll D = y1 *y2;
			ll gc = gcd(abs(N), abs(D));
			D /= gc;
			N /= gc;
			pair<ll, ll>ans = fix(N, D);
			cout << ans.first << " / " << ans.second << endl;
		}
		else
		{
			swap(x2, y2);
			ll N = x1 * x2;
			ll D = y1 * y2;
			ll gc = gcd(abs(N), abs(D));
			D /= gc;
			N /= gc;
			pair<ll, ll>ans = fix(N, D);
			cout << ans.first << " / " << ans.second << endl;
		}
		
	}


}