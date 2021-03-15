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
vector<int>v;
int n;
void init()
{
	cin >> n;
	v.clear();
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
}
bool can(int mid)
{
	int lst = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i] - lst == mid)mid--;
		else if (v[i] - lst > mid)return 0;
		lst = v[i];
	}
	return 1;
}
int main()
{
	nGu();
	int t;
	cin >> t;
	int cnt = 1;
	while (t--)
	{
		init();
		int l = 0, r = *max_element(all(v))+1, ans = r;
		while (l < r)
		{
			int mid = l+(r - l) / 2; //last t
			if (can(mid))
			{
				ans =min(ans, mid);
				r = mid;
			}
			else
			{
				l = mid + 1;
			}
			//cout << mid << endl;
		}
		
		cout << "Case "<<cnt++<<": "<<ans<< endl;
	}


}