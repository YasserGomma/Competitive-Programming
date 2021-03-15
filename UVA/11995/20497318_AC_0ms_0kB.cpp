#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<string>
using namespace std;
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
int main()
{
	_Sectumsempra_();
	int n;
	while (cin >> n)
	{
		vector<int>vin;
		vector<int>vout;
		stack<int>st;
		queue<int>qu;
		priority_queue<int>pr;
		int stc = 1, que = 1, prq = 1;
		fori(n)
		{
			int x, y;
			cin >> x >> y;
			if (x == 1)
			{
				vin.push_back(y);
				if (stc)	st.push(y);
				if (que)	qu.push(y);
				if (prq)pr.push(y);
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