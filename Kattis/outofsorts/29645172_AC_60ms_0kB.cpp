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
	
	ll n, m, a, c,x0;
	cin >> n >> m >> a >> c>>x0;
	vector<ll>v(n);
	cin >> v[0];
	for (int i = 0; i < n; i++) {
		if (!i)
			v[i] = (a * x0 + c) % m;
		else
			v[i] = (a * v[i - 1] + c) % m;
	}
	int cnt = 0;
	for (auto it : v) {
		//cout << it << endl;
		int l = 0, h = n-1;
		while (l <= h)
		{
			int mid = (l + h) >> 1;
			if (v[mid] == it)
			{
				cnt++;
				break;
			}
			else if (v[mid] > it)
			{
				h = mid - 1;
			}
			else
				l = mid + 1;
		}
	}
	cout << cnt << endl;
}