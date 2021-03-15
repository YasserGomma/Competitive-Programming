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
vector <set<pair<int, int>>>ans(4);
int main()
{
	nGu();
	int n;cin >> n;
	vector<int>p(n), a(n), b(n);
	for (int i = 0; i < n; i++)cin >> p[i];
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < n; i++)cin >> b[i];

	for (int i = 0; i < n; i++) {
		ans[b[i]].insert({p[i], i });
		ans[a[i]].insert({p[i], i });
	}

	int m;cin >> m;
	while (m--) {
		int c;cin >> c;
		if (ans[c].empty()) {
			cout << -1 << " ";
		}
		else {
			cout << p[ans[c].begin()->second] << " ";
			int id = ans[c].begin()->second;
			ans[a[id]].erase({ p[id],id });
			ans[b[id]].erase({ p[id],id });
		}
	}
}
