/*
		 /\_/\
   )____/ o o \
  /~____  =?= /
 (______)__m_m)
 MEOOO!!!
 */
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<vector>
#include<string>

using namespace std;
void yasser_gomma()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}
#define MEO yasser_gomma();
#define ll long long
#define r0 return 0;
#define all(v) ((v).begin()), ((v).end())
ll fact(ll n)
{
	ll f = 1;
	for (int i = 1; i <= n; i++)
	{
		f *= i;
	}
	return f;
}

int main()
{
	MEO
		string s;
	ll a, x = 0;
	cin >> a;
	deque<int>dq;
	while (a--)
	{
		cin >> s;
		if (s == "push_back")
		{
			int n;
			cin >> n;
			if (x % 2 == 0) {
				dq.push_back(n);
			}
			else
				dq.push_front(n);

		}
		else if (s == "toFront")
		{
			int n;
			cin >> n;
			if (x % 2 == 0) {
				dq.push_front(n);
			}
			else
				dq.push_back(n);
		}
		else if (s == "back")
		{
			if (dq.size() == 0)
				cout << "No job for Ada?" << endl;
			else {
				if (x % 2 == 0) {
					cout << dq.back() << endl;
					dq.pop_back();
				}
				else
				{
					cout << dq.front() << endl;
					dq.pop_front();
				}
			}
		}
		else if (s == "front")
		{
			if (dq.size() == 0)
				cout << "No job for Ada?" << endl;
			else {
				if (x % 2 == 0) {
					cout << dq.front() << endl;
					dq.pop_front();
				}
				else
				{
					cout << dq.back() << endl;
					dq.pop_back();
				}
			}
		}
		else if (s == "reverse")
		{
			x++;
		}

	}
}


