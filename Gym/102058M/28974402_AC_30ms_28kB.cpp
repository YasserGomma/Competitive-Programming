#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>	
using namespace std;
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
#define all(v) ((v).begin()), ((v).end())	
#define sz(v) v.size()
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
constexpr auto EPS = 1e-9;
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
int main()
{
	COME_BACK();
	ll n, k, a;
	cin >> n >> k >> a;
	vector<ll>s(n), t(n);
	for (int i = 0; i < n; i++)
		cin >> s[i] >> t[i];
	vector<ll>ans(n);
	for (int i = 0; i < n; i++)
	{
		if (a * s[i] > k)
		{
			ans[i] = (k / a) + (k % a != 0);
			
		}
		else if (a * s[i] == k)
		{
			ans[i] = s[i];
		}
		else
		{
			ll to = a * s[i];
			int hm = k / to;
		//	cout << to << " " << hm << endl;
			if (k % to == 0)
				ans[i] = (hm * s[i]) + ((hm - 1) * t[i]);
			else
			{
				ans[i] = (hm * s[i]) + (hm  * t[i]);
				ll k1 = k-(hm * s[i] * a);
				//cout << k1<<"K!" << endl;
				ans[i] += (k1 / a) + (k1 % a != 0);
			}
		}
	//	cout << ans[i] << endl;
	}
	cout << *min_element(all(ans));

}