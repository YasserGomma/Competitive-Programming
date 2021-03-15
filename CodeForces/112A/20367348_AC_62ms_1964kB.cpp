#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
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
typedef long long ll;
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
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll arr[100007], pr[100007];
int add[100007];
int main()
{
	_Sectumsempra_();
	string s, x;
	cin >> s >> x;
	forsz(s)
	{
		if (s[i] >= 97)
			s[i] -= 32;
	}
	forsz(x)
	{
		if (x[i] >= 97)
			x[i] -= 32;
	}
	if (s == x)
		cout << 0 << endl;
	else if (s > x)
		cout << 1 << endl;
	else
		cout << -1 << endl;
  //cout << s << " " << x;


}