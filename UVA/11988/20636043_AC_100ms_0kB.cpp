#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define sz(s)	(int)(s.size())
typedef	long long ll;
int main()
{
	string s;
	while (getline(cin, s)) {
		bool h = 0;
		deque<char>q;
		stack<char> st;
		for (char ch : s) {
			if (ch == ']' || ch == '[') {
				h = (ch == '[');
				while (!st.empty()) {
					q.push_front(st.top());
					st.pop();
				}
			}
			else {
				if (h) st.push(ch);
				else q.push_back(ch);
			}
		}
		while (!st.empty()) {
			q.push_front(st.top());
			st.pop();
		}
		for (int i = 0; i < sz(q); i++)
			cout << q[i];
		cout << endl;
	}
}