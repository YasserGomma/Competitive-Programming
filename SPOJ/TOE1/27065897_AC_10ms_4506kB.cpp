#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>	
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
#define all(v) ((v).begin()), ((v).end())	
#define sz(v) v.size()
#define endl "\n"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
constexpr auto EPS = 1e-9;
const int mod = 1e9 + 7;
const double pi = acos(-1);
int dx[] = { 0 , 0 , 1 , -1 , 1 , 1 , -1 , -1 };
int dy[] = { 1 ,-1 , 0 , 0 , -1 , 1 ,  1 , -1 };
ll gcd(ll a, ll b) { return (a) ? gcd(b % a, a) : b; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
void GOAT()
{
	std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);// freopen("out.txt", "w", stdout);
#endif
}
bool win(string s)
{
	bool row =
		(s[0] != '.' && s[0] == s[1] && s[1] == s[2]) ||
		(s[3] != '.' && s[3] == s[4] && s[4] == s[5]) ||
		(s[6] != '.' && s[6] == s[7] && s[7] == s[8]);
	bool col=
		(s[0] != '.' && s[0] == s[3] && s[3] == s[6]) ||
		(s[1] != '.' && s[1] == s[4] && s[4] == s[7]) ||
		(s[2] != '.' && s[2] == s[5] && s[5] == s[8]);
	bool dig=
		(s[0] != '.' && s[0] == s[4] && s[4] == s[8]) ||
		(s[2] != '.' && s[2] == s[4] && s[4] == s[6]);
	return row | col | dig;

		
}
int main()
{
	//GOAT();
	int t; cin >> t;
	while (t--) {
		string board = "";
		int cnt = 3;
		while (cnt--)
		{
			string s;
			cin >> s;
			board += s;
		}
		string scr = ".........",ans="no";
		queue<pair<string, bool>>q;
		q.push({ scr,1 });
		while (!q.empty())
		{
			pair<string, bool>cur = q.front();
			q.pop();
			if (cur.first == board)
			{
				ans = "yes";
				break;
			}
			if (win(cur.first))continue;
			for (int i = 0; i < 9; i++)
			{
				if (cur.first[i] == '.') {
					cur.first[i] = (cur.second ? 'X' : 'O');
					if (cur.first[i] == board[i])
						q.push({ cur.first,cur.second ^ 1 });
					cur.first[i] = '.';
				}

			}
		}
		cout << ans << endl;
	}
}