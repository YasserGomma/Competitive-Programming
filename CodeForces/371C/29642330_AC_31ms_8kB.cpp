#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
#include<unordered_map>
#ifdef _MSC_VER
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif
using namespace std;
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
#define all(v) ((v).begin()), ((v).end())	
#define sz(v) v.size()
#define endl "\n"
typedef long long ll;
typedef  long long int lli;
typedef vector<int> vi;
typedef pair<int, int> pii;
constexpr auto EPS = 1e-7;
const int mod = (int)1e9 + 7;
const double pi = acos(-1);
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
ll gcd(ll a, ll b) { return (a) ? gcd(b % a, a) : b; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
void COME_BACK()
{
	std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
string x;
map<char, int>mp;
ll nb, ns, nc, b, s, c, r;
bool can(ll mid)
{

	ll nnb, nnc, nns;
	nnb = mp['B'] * mid;
	nnc = mp['C'] * mid;
	nns = mp['S'] * mid;
	nnb -= nb, nnc -= nc, nns -= ns;
	ll ans = 0LL;
	if (mp['B']&&nnb>0)ans += (nnb * b);
	if (mp['C']&&nnc>0)ans += (nnc * c);
	if (mp['S']&&nns>0)ans += (nns * s);
	//cout << mid<<" "<<ans << " " << nnb<<" "<<nnc<<" "<<nns << endl;
	return (ans <= r);

}
int main()
{
	COME_BACK();
	cin >> x;
	cin >> nb >> ns >> nc;
	cin >> b >> s >> c;
	cin >> r;
	for (auto i : x)mp[i]++;
	ll l = 0, r = 2e12, ans = 0LL;
	while (l <= r)
	{
		ll mid = (l + r) / 2;
		if (can(mid))
		{
			l = mid + 1;
			ans = mid;
		}
		else
			r = mid - 1;
	}
	cout << ans << endl;
}