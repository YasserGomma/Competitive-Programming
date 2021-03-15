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
bool isPrime(int n)
{
	
	if (n % 2 == 0 && n != 2)
		return 0;
	for (int i = 2; i <= n/i; i += 1 + (i & 1))
		if (n % i == 0)
			return 0;
	return 1;
}
int main()
{
	nGu();
	int cnt = 1;
	map<char, int>mp;
	for (char i = 'a'; i <= 'z'; i++)
		mp[i] = cnt++;
	for (char i = 'A'; i <= 'Z'; i++)
		mp[i] = cnt++;
	string s;
	while (cin >> s)
	{
		int sum = 0;
		for (auto it : s)
			sum += mp[it];
		if (isPrime(sum))
			cout << "It is a prime word." << endl;
		else
			cout << "It is not a prime word." << endl;
	}
}