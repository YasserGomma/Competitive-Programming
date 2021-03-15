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
int p, q, r, s, t, u;
double isValid(double x) {
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

double bs() {
	double lo = 0.0, hi = 1.0, ans = -1.0;
	for (int i = 0; i < 200; i++)
	{
		double mid = (lo + hi) / 2.0;
		if (fabs(isValid(mid) - 0) <= EPS)
			ans = mid;
		else
		{
			if (isValid(mid) < 0.0)
				hi = mid;
			else
				lo = mid;
		}
	}
	return ans;
}

int main()
{
	nGu();
	while (cin >> p >> q >> r >> s >> t >> u)
	{
		double ans = bs();
		if (ans != -1.00)
			cout << fixed << setprecision(4) << bs() << endl;
		else
			cout << "No solution" << endl;
	}


}