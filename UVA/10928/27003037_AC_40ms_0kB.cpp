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
void GOAT()
{
	std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
int main()
{
	GOAT();
	int t;
	cin >> t;
	while (t--)
	{
		
		int n,x, idx = 1, mn = INT_MAX;
		cin >> n;
		vector<int>v(n+1);
		stringstream str;
		string s;
		cin.ignore();
		for(int i=1;i<=n;i++)
		{
			getline(cin, s);
			str << s;
			int cnt = 0;
			while(str>>x)cnt++;
			str.clear();
			v[i] = cnt;
			mn = min(mn, cnt);
		}
		bool _1 = 0;
		for (int i = 1; i <= n; i++) 
		{
			if (v[i] == mn) 
			{
				if (_1)cout << " ";
				_1 = 1;
				cout <<i;
			}
			
		}
		cout << endl;
	}
}