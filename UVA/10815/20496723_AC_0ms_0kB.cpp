#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<string>

using namespace std;
void _Sectumsempra_()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
#endif
}
bool cmp(pair<string, pair<int, int>>p1, pair<string, pair<int, int>>p2)
{
	if (p1.first != p2.first)return p1.first < p2.first;
	if (p1.second.first != p2.second.first)return p1.second.first > p2.second.first;
	if (p1.second.second != p2.second.second) return p1.second.second < p2.second.second;

}
//int BinarySearch(int Start, int End, int X)
//{
//	while (Start <= End)
//	{
//		int Middle = (Start + End) / 2;
//		if (arr[Middle] < X)
//		{
//			Start = Middle + 1;
//		}
//		else if (arr[Middle] > X)
//		{
//			End = Middle - 1;
//		}
//		else
//		{
//			return Middle;
//		}
//	}
//	return -1;
//}

typedef long long ll;
#define trace(x) cout<<"#trace   "<<x<<endl;
#define bay_bay return 0;
#define fori(n) for(int i=0;i<n;++i)
#define forsz(s )for(int i=0;i<s.size();++i)
#define all(v) ((v).begin()), ((v).end())
#define read(FILE) freopen(FILE,"r",stdin)
#define write(FILE) freopen(FILE,"w",stdout)
#define sz(v) v.size()
#define endl "\n"
#define sfi(n) scanf("%d",&n)
#define pfi(n) printf("%d",n)
#define sfll(n) scanf("%ld",&n)
#define pfll(n) printf("%ld",n)
#define sff(n) scanf("%f",&n)
#define pff(n) printf("%f",n)
#define sfd(n) scanf("%lf",&n)
#define pfd(n) printf("%lf",n)
#define pfdset(n) printf("%.3lf",n)
#define sfc(n) printf("%c",&n)
#define pfc(n) printf("%c",n)
ll npr(ll n, ll r)
{
	ll ans = 1;
	for (ll i = n - r + 1; i <= n; i++)
	{
		ans *= i;
		ans %= 1000000007;
	}
	return ans;
}
ll fact(ll n)
{
	if (n <= 1)
		return 1;
	return n * fact(n - 1) % 1000000009;
}

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

int main()
{

	string s;
	map<string, int>mp;
	while (getline(cin, s))
	{
		s += ' ';

		string fin = "";
		forsz(s)
		{
			if (!isalpha(s[i]))
			{
				mp[fin]++;
				fin = "";
			}
			if (isalpha(s[i])) {
				if (s[i] < 'a')
					s[i] += 32;
				fin += s[i];
			}
		}
	}
	for (auto it : mp)
	{
		string x = it.first;
		if (isalpha(x[0]))
			cout << x << endl;
	}
}

