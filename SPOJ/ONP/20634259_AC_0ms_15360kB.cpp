#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define sz(s)	(int)(s.size())
typedef	long long ll;
int main()
{

	int n;
	string str;
	cin >> n;
	while (n--) {
		int start = -1;
		vector<stack<char>>v1(409);
		cin >> str;
		for (int i = 0; i < sz(str); i++) 
		{
			if (str[i] == '(') start++;
			else if (str[i] >= 'a' && str[i] <= 'z')cout << str[i];
			else if (str[i] == ')') {
				while (!v1[start].empty())
				{
					cout << v1[start].top();
					v1[start].pop();
				}
				start--;
			}
			else v1[start].push(str[i]);
		}
		cout << endl;
	}
}