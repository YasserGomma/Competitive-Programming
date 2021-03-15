#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>	
using namespace std;
typedef long long ll;
#define bay_bay return 0;
#define fori(n) for(int i=0;i<n;++i)
#define for1(n) for(int i=1;i<=n;i+=3)
#define all(v) ((v).begin()), ((v).end())	
#define sz(v) v.size()
#define endl "\n"
constexpr auto EPS = 1e-9;
#define ff fflush(stdout);
const int mod = 1000000007LL;
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
void GOAT()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("output.txt", "w	", stdout);
#else
#endif
}
struct day
{
	ll a, b, c;

};
day days[100009];
int main()
{
	//GOAT();
int n;
cin>>n;
for (int i = 1; i <= n;i++)
		cin >> days[i].a>>days[i].b>>days[i].c;
for (int i = 2; i <= n;i++)
{
	days[i].a += max(days[i - 1].b, days[i - 1].c);
	days[i].b+= max(days[i - 1].a, days[i - 1].c);
	days[i].c += max(days[i - 1].b, days[i - 1].a);

}
cout << max(days[n].a, max(days[n].b, days[n].c));
	
}