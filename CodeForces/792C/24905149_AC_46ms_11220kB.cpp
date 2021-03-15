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
#define oo 0x3f3f3f3fLL
#define pb					push_back
#define P(x)				cout<<#x<<" = { "<<x<<" }\n"
void GOAT()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w	", stdout);
#else
#endif

}
string s;
int mem[100005][4][2];
int solve(int i,int rem,int notled)
{
	if (i == sz(s))
		return (!notled||rem)*oo;
	int& ret = mem[i][rem][notled];
	if (~ret)return ret;
	ret = solve(i+1, rem, notled) + 1;
	if ((s[i] == '0' && notled) || s[i] > '0')
		ret = min(ret, solve(i + 1, (rem + s[i] - '0') % 3, 1));
	return ret;
}
void build(int i, int rem, int notled)
{
	if (i == sz(s))return ;
	int ret = solve(i, rem, notled);
	if (ret == 1 + solve(i + 1, rem, notled)) {
		build(i + 1, rem, notled);
		return;
	}
	cout << s[i];
	build(i + 1, (rem + s[i] - '0') % 3, 1);
}

int main() {
	GOAT();
	clr(mem, -1);
	cin >> s;
	if (solve(0, 0, 0) <=sz(s))return build(0, 0, 0),0;
	if (s.find('0') != string::npos)return cout << 0, 0;
		cout << -1 << endl;




}
