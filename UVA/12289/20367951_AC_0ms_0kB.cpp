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
	string ar = "";
	string x;
	ll n;
	cin >> n;
	while (n--)
	{
		cin >> x;
		if (x.size() == 3)
		{
			if (x == "one" || x[0] == 'o' && x[1] == 'n' || x[0] == 'o' && x[2] == 'e' || x[1] == 'n' && x[2] == 'e')
			{
				cout << 1;
			}
			else if (x == "two" || x[0] == 't' && x[1] == 'w' || x[1] == 'w' && x[2] == 'o' || x[0] == 't' && x[2] == 'o')
			{
				cout << 2;
			}
		}
		else
		{
			cout << 3;
		}


		cout << endl;
	}
}