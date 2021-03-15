#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
#define pb push_back
#define mm(v) memset(v, 0, sizeof(v))
#define deb(x)   cout << "[" <<#x << "=" << x << "]" << endl
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
constexpr auto EPS = 1e-7;
const int mod = (int)1e9 + 7;
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

int main() {
	nGu();
	int n;
	while (cin >> n)
	{
		vector<int>vin;
		stack<int>st;
		queue<int>qu;
		priority_queue<int>pr;
		int stc = 1, que = 1, prq = 1;
		for(int i=0;i<n;i++)
		{
			int x, y;
			cin >> x >> y;
			if (x == 1)
			{
				vin.push_back(y);
				if (stc)	st.push(y);
				if (que)	qu.push(y);
				if (prq)    pr.push(y);
			}
			else
			{
				if (stc)
				{
					if (st.empty() || st.top() != y) {
						stc = 0;
					}
					else {
						st.pop();
					}
				}
				if (que)
				{
					if (qu.empty() || qu.front() != y) {
						que = 0;
					}
					else {
						qu.pop();
					}
				}
				if (prq)
				{
					if (pr.empty() || pr.top() != y) {
						prq = 0;
					}
					else {
						pr.pop();
					}
				}
			}
		}
		if (stc + prq + que == 0)
			cout << "impossible" << endl;
		else if (stc + prq + que > 1)
			cout << "not sure" << endl;
		else
		{
			if (stc)
				cout << "stack" << endl;
			else if (prq)
				cout << "priority queue" << endl;
			else if (que)
				cout << "queue" << endl;
		}

	}



}