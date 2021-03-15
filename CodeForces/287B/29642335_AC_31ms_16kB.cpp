#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>	
using namespace std;
typedef long long ll;
#define all(v) ((v).begin()), ((v).end())	
#define sz(v) v.size()
#define endl "\n"
constexpr auto EPS = 1e-9;
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
ll gcd(ll a, ll b) { return (a) ? gcd(b % a, a) : b; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
void GOAT()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
#endif
}
ll n, k;
ll can(ll mid)
{
	ll ans = ((k * (k - 1)) / 2) - ((mid * (mid - 1)) / 2);
	return ans ;
}
int main()
{
	cin >> n >> k;
	if ((k * (k - 1)) / 2 < n-1)return cout << -1, 0;
	if(n==1)return cout << 0, 0;
	ll l = 1, r = k-1, mid, ans = 0;
	while (l <= r)
	{
		mid = l + (r - l) / 2;
		if (can(mid) > n-1)l = mid + 1, ans = max(mid, ans);
		else if (can(mid) == n-1)return cout << k - mid << endl, 0;
		else r = mid-1;
	}
	cout << k-ans << endl;
	
}