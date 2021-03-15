#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define sz(s)	(int)(s.size())
typedef	long long ll;
int main()
{

	string s, x;
	set<string> st;
	while (cin >> s) {
		if (!x.empty()) { s = x + s; x.clear(); }
		if (s.back() == '-') { s.pop_back(); x = s; continue; }
		string y;
		for (char& ch : s) {
			ch = tolower(ch);
			if (!isalpha(ch) && ch != '-') ch = ' ';
		}
		for (char ch : s) {
			if (ch != ' ') y.push_back(ch);
			else if (!y.empty())
				st.insert(y), y.clear();
		}
		if (!y.empty())
			st.insert(y), y.clear();;
	}
	for (auto it : st)
		cout << it << endl;
}