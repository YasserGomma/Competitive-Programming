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
#define clr(v, d)		memset(v, d, sizeof(v))
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
int v[209], n;
int mem[209][209];
int LIS(int i, int prev)
{
	if (i == n)return 0;
	int& ret = mem[i][prev];
	if (~ret)return ret;
	int choice1 = LIS(i + 1, prev); // LEAVE
	int choice2 = 0;

	if (prev == n || v[prev] < v[i])
		choice2 = LIS(i + 1, i) + 1;

	return ret = max(choice1, choice2);
}
void print(int i, int prev)
{
	if (i == n)return  ;

	int leave = LIS(i+1,prev);
	int pick = LIS(i, prev);
	if (leave == pick)
		print(i + 1, prev);
	else
	{
		cout << v[i] << " ";
		print(i + 1, i);
	}
}
int main()
{
	
	while (cin >> n && n) {
		clr(mem, -1);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		int ans=LIS(0, n);
		cout << ans << " ";
		print(0, n);
		cout << endl;
	}
}
