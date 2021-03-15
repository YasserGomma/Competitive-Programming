#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define sz(s)	(int)(s.size())
typedef	long long ll;
int main()
{

	ll n;
	while (cin >> n)
	{
		if (!n)
			return 0;
		if (n == 1)
		{
			cout << "Discarded cards:" << endl;
			cout << "Remaining card: " << 1 << endl;


		}
		else
		{
			deque<int>q;
			vector<int>v;
			for (int i = 1; i <= n; i++)
				q.push_back(i);
			while (sz(q) > 1)
			{
				v.push_back(q.front());
				q.pop_front();
				int x = q.front();
				q.push_back(x);
				q.pop_front();
			}
			//cout << q.front() << endl;
			cout << "Discarded cards: ";
			for (int i = 0; i < sz(v); i++)
			{

				if (i < sz(v) - 1) {
					cout << v[i] << ", ";
				}
				else
					cout << v[i] << endl;



			}

			cout << "Remaining card: " << q.front() << endl;
		}
	}
}