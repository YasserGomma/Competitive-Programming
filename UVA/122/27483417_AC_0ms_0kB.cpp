#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include <cstring>
#include<unordered_map>
using namespace std;
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
#define all(v) ((v).begin()), ((v).end())	
#define sz(v) v.size()
#define endl "\n"
typedef long long ll;
typedef  long long int lli;
typedef vector<int> vi;
typedef pair<int, int> pii;
constexpr auto EPS = 1e-7;
const int MOD = (int)1e9 + 7;
int dxn[] = { -1,-2,-2,-1,1,2,2,1};
int dyn[] = { -2,-1,1,2,2,1,-1,-2};
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
ll gcd(ll a, ll b) { return (a) ? gcd(b % a, a) : b; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
void COME_BACK()
{
    std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
     //freopen("out.txt", "w", stdout);
#endif
}

struct node {
	bool val;	
	int v;
	node* left, * right;
	node() :val(0), left(NULL), right(NULL) {}
};
node* root;
const int mxn = 1000 + 10;
char s[mxn];
bool flag;
vector<int>ans;
void add(int v,	char *s)
{
	int n = strlen(s);
	node *u = root;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'L')
		{
			if (u->left == NULL)u->left = new node();
			u = u->left;
		}
		else if(s[i]=='R')
		{
			if (u->right == NULL)u->right = new node();
			u = u->right;
		}
	}
	if (u->val)flag = 1;
	u->v = v;
	u->val = 1;

}
bool in()
{
	flag = 0;
	root = new node();
	while (true)
	{
		if (scanf("%s",s) != 1)return 0;
		if (!strcmp(s,"()"))break;
		int v;
		sscanf(&s[1], "%d", &v);
		add(v, strchr(s, ',') + 1);
		//add();
	}
	return 1;
}
bool traversal()
{
	queue<node*>q;
	ans.clear();
	q.push(root);
	while (!q.empty())
	{
		node *p = q.front(); q.pop();
		if (!p->val)return 0;
		ans.push_back(p->v);
		if (p->left != NULL)q.push(p->left);
		if (p->right != NULL)q.push(p->right);
	}
	return 1;
}
int main()
{
    COME_BACK();
	
	while (in())
	{
		if (flag)
		{
			cout << "not complete" << endl;
			continue;
		}
		if (traversal())
		{
			for (int i = 0; i < sz(ans); i++)
			{
				if (i)cout << " ";
				cout << ans[i];
			}
			cout << endl;
		}
		else
				cout << "not complete" << endl;
	}

}
