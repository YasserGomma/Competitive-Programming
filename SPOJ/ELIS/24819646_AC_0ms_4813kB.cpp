#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>	
using namespace std;
#define all(v)			((v).begin()), ((v).end())
#define sz(v)			((int)((v).size()))
#define clr(v, d)		memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
typedef long long         ll;
const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }
#define pb					push_back
#define P(x)				cout<<#x<<" = { "<<x<<" }\n"
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
int v[21], n;
int mem[100][100];
int LIS(int i, int prev)
{
	if (i == n)
		return 0;
	int& ret = mem[i][prev];
	if (~ret)return ret;
	int choice1 = LIS(i + 1, prev); // LEAVE
	int choice2 = 0;

	if (prev == n || v[prev] < v[i])
		choice2 = LIS(i + 1, i) + 1;

	return ret= max(choice1, choice2);
}
int main()
{
	GOAT();
	clr(mem, -1);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	cout << LIS(0,n) << endl;




}