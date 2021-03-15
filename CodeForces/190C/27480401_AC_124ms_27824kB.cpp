#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
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
const int MOD = (int)1e9 + 7;
int dxn[] = { -1,-2,-2,-1,1,2,2,1};
int dyn[] = { -2,-1,1,2,2,1,-1,-2};
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
vector<string> v, ans;
int idx = 0,cant;
void solve() {
	if (idx >= sz(v))
	{
		cant = 1;
		return;
	}
	ans.push_back(v[idx]);
	if (v[idx] == "pair") 
	{
		ans.push_back("<");
		idx++;
		solve();
		ans.push_back(",");
		solve();
		ans.push_back(">");
		return;
	}
	idx++;
}
int main()
{
    COME_BACK();
	int n;cin >> n;
	string s;
	while (cin >> s)v.push_back(s);
	solve();
	if (idx != sz(v)||cant)cout << "Error occurred" << endl;
	else for (int i = 0; i < sz(ans); i++)cout << ans[i];


}
